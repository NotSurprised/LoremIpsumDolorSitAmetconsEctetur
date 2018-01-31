#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>//for sockaddr_in
#include <arpa/inet.h>//for socket

int powab(int a,int b)
{
	int ans = 1;
	int x;
	for(x=0;x<b;x++)
	{
		ans=ans*a;
	}	
	return ans;
}

int main()
{
	struct TCPheader
	{
		u_short th_sport[16];/* source port */
		u_short th_dport[16];/* destination port */
		u_int th_seq;/* sequence number */
		u_int th_ack;/* acknowledgement number */
		u_char headlen[4];/*head length*/
		u_char unused[6];/*unused*/
		u_char th_flags;
		#define TH_URG 0x20
		#define TH_ACK 0x10
		#define TH_PUSH 0x08
		#define TH_RST 0x04
		#define TH_SYN 0x02
		#define TH_FIN 0x01
		#define TH_FLAGS (TH_URG|TH_ACK|TH_PUSH|TH_RST|TH_SYN|TH_FIN)		
		/*bool th_URG[1];
		bool th_ACK[1];
		bool th_PSH[1];
		bool th_RST[1];
		bool th_SYN[1];
		bool th_FIN[1];*/
		u_short th_win;   /* window */
		u_short th_sum;   /* checksum */
		u_short th_urp;   /* urgent pointer */	
	};
	int RTT = 200;
	int threshold = 65535;
	int MSS = 512;
	char buf[10240];
	printf("\n=================\n");
	printf("Set RTT delay = %d ms\n", RTT);
	printf("Set threshold = %d bytes\n", threshold);
	printf("Set MSS = %d bytes\n", MSS);
	printf("Buffer size = %d bytes\n", sizeof(buf));


	int fd=socket(AF_INET,SOCK_DGRAM,0);
	if(fd==-1)
	{
		//perror("socket create error!\n");
		exit(-1);
	}
	//printf("socket fd=%d\n",fd);


	struct sockaddr_in addr_from;//自己的地址
	addr_from.sin_family=AF_INET;
	addr_from.sin_port=10220;
	//addr_from.sin_addr.s_addr=htons(INADDR_ANY);
	addr_from.sin_addr.s_addr=inet_addr("127.0.0.1");
	
	struct TCPheader packet;

	printf("Server's ip is %s\nServer is listening on port %d\n",inet_ntoa(addr_from.sin_addr),addr_from.sin_port); 
	printf("=================\nListening...\n");

	int r;
	r=bind(fd,(struct sockaddr*)&addr_from,sizeof(addr_from));
	if(r==-1)
	{
		printf("Bind error!\n");
		close(fd);
		exit(-1);
	}
	//printf("Bind successfully.\n");

	struct sockaddr_in to;
	socklen_t len;
	len=sizeof(to);

	int temp;
	//=============================3way==================================
	r=recvfrom(fd,(struct TCPheader*)&packet.th_flags,1,0,(struct sockaddr*)&to,&len);
	if (packet.th_flags==0x02)
	{
		printf("Receive a SYN packet from [ %s : %d ] \n",inet_ntoa(to.sin_addr),to.sin_port);
		r=recvfrom(fd,(struct TCPheader*)&packet.th_seq,10,0,(struct sockaddr*)&to,&len);
		r=recvfrom(fd,(struct TCPheader*)&packet.th_ack,10,0,(struct sockaddr*)&to,&len);
		temp = packet.th_seq;
		packet.th_seq = packet.th_ack;
		packet.th_ack = temp;
		printf("\tGet a packet(seq=%d , ack=%d)\n",packet.th_seq,packet.th_ack);
	}

	packet.th_flags=0x02;
	packet.th_seq=packet.th_seq+1;
	packet.th_ack=(rand() % 10000);
	printf("Send a SYN/ACK packet to [%s : %d]\n",inet_ntoa(to.sin_addr),to.sin_port);
	sendto(fd,(struct TCPheader*)&packet.th_flags,1,0,(struct sockaddr*)&to,sizeof(to));
	sendto(fd,(struct TCPheader*)&packet.th_seq,32,0,(struct sockaddr*)&to,sizeof(to));
	sendto(fd,(struct TCPheader*)&packet.th_ack,32,0,(struct sockaddr*)&to,sizeof(to));

	r=recvfrom(fd,(struct TCPheader*)&packet.th_flags,1,0,(struct sockaddr*)&to,&len);
	if (packet.th_flags==0x10)
	{
		printf("Receive an ACK packet from [ %s : %d ] \n",inet_ntoa(to.sin_addr),to.sin_port);
		r=recvfrom(fd,(struct TCPheader*)&packet.th_seq,10,0,(struct sockaddr*)&to,&len);
		r=recvfrom(fd,(struct TCPheader*)&packet.th_ack,10,0,(struct sockaddr*)&to,&len);
		temp = packet.th_seq;
		packet.th_seq = packet.th_ack;
		packet.th_ack = temp;
		printf("\tGet a packet(seq=%d , ack=%d)\n",packet.th_seq,packet.th_ack);
	}
	printf("Complete three way handshake\n=================\n");
	//=============================3way==================================
	printf("Begin to send file, %d bytes\n", sizeof(buf));
	
	int i;
	int Cwnd;
	int Rwnd=sizeof(buf);
	for(i=0;i<=10; i++)
	{
		//sendto(fd,buf[i],1,0,(struct sockaddr*)&to,sizeof(to));
		packet.th_seq=packet.th_seq+1;
		packet.th_ack=powab(2,i+1);
		sendto(fd,(struct TCPheader*)&packet.th_seq,32,0,(struct sockaddr*)&to,sizeof(to));
		sendto(fd,(struct TCPheader*)&packet.th_ack,32,0,(struct sockaddr*)&to,sizeof(to));
		Cwnd = powab(2,i);
		printf("(Cwnd = %d, Rwnd =%d, Send Packet at: %d byte)\n",Cwnd,Rwnd,Cwnd);
		printf("\tGet a packet(seq=%d , ack=%d)\n",packet.th_seq,packet.th_ack);
		Rwnd=sizeof(buf)-powab(2,i);
		usleep(RTT);
	}
	printf("Finish to send file\n");
	//=============================4way==================================
	printf("\n=================\n");
	packet.th_flags=0x01;
	packet.th_seq=packet.th_seq+1;
	//packet.th_ack=(rand() % 10000);
	printf("Send a FIN packet to [%s : %d]\n",inet_ntoa(to.sin_addr),to.sin_port);
	sendto(fd,(struct TCPheader*)&packet.th_flags,1,0,(struct sockaddr*)&to,sizeof(to));
	sendto(fd,(struct TCPheader*)&packet.th_seq,32,0,(struct sockaddr*)&to,sizeof(to));
	sendto(fd,(struct TCPheader*)&packet.th_ack,32,0,(struct sockaddr*)&to,sizeof(to));

	r=recvfrom(fd,(struct TCPheader*)&packet.th_flags,1,0,(struct sockaddr*)&to,&len);
	if (packet.th_flags==0x10)
	{
		printf("Receive an ACK packet from [ %s : %d ] \n",inet_ntoa(to.sin_addr),to.sin_port);
		r=recvfrom(fd,(struct TCPheader*)&packet.th_seq,10,0,(struct sockaddr*)&to,&len);
		r=recvfrom(fd,(struct TCPheader*)&packet.th_ack,10,0,(struct sockaddr*)&to,&len);
		temp = packet.th_seq;
		packet.th_seq = packet.th_ack;
		packet.th_ack = temp;
		printf("\tGet a packet(seq=%d , ack=%d)\n",packet.th_seq,packet.th_ack);
	}

	r=recvfrom(fd,(struct TCPheader*)&packet.th_flags,1,0,(struct sockaddr*)&to,&len);
	if (packet.th_flags==0x01)
	{
		printf("Receive a FIN packet from [ %s : %d ] \n",inet_ntoa(to.sin_addr),to.sin_port);
		r=recvfrom(fd,(struct TCPheader*)&packet.th_seq,10,0,(struct sockaddr*)&to,&len);
		r=recvfrom(fd,(struct TCPheader*)&packet.th_ack,10,0,(struct sockaddr*)&to,&len);
		temp = packet.th_seq;
		packet.th_seq = packet.th_ack;
		packet.th_ack = temp;
		printf("\tGet a packet(seq=%d , ack=%d)\n",packet.th_seq,packet.th_ack);
	}

	packet.th_flags=0x10;
	packet.th_seq=packet.th_seq+1;
	//packet.th_ack=(rand() % 10000);
	printf("Send an ACK packet to [%s : %d]\n",inet_ntoa(to.sin_addr),to.sin_port);
	sendto(fd,(struct TCPheader*)&packet.th_flags,1,0,(struct sockaddr*)&to,sizeof(to));
	sendto(fd,(struct TCPheader*)&packet.th_seq,32,0,(struct sockaddr*)&to,sizeof(to));
	sendto(fd,(struct TCPheader*)&packet.th_ack,32,0,(struct sockaddr*)&to,sizeof(to));

	printf("Complete four way handshake\n=================\n");
	//=============================4way==================================

	close(fd);
	return 0;
}
