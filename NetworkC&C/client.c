#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <netinet/in.h>//for sockaddr_in
#include <arpa/inet.h>//for socket 

int main()
{
	srand(time(NULL));
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
		u_short th_win;   /* window */
		u_short th_sum;   /* checksum */
		u_short th_urp;   /* urgent pointer */	
	};
	
	int RTT = 200;
	//int threshold = 65535;
	//int MSS = 512;
	char buf[10240];

	int fd=socket(AF_INET,SOCK_DGRAM,0);

	if(fd==-1)
	{
		//perror("socket create error!\n");
		exit(-1);
	}
	//printf("socket fd=%d\n",fd);

	struct sockaddr_in addr_to;//目標地址
	addr_to.sin_family=AF_INET;
	addr_to.sin_port=10220;
	//addr_to.sin_addr.s_addr=htons(INADDR_ANY);
	addr_to.sin_addr.s_addr=inet_addr("127.0.0.1");
	
	struct sockaddr_in addr_from;//自己的地址
	addr_from.sin_family=AF_INET;
	addr_from.sin_port=10219;
	
	struct TCPheader packet;
	
	int r;  
	r=bind(fd,(struct sockaddr*)&addr_from,sizeof(addr_from));


	if(r==-1)
	{
		printf("Bind error!\n");
		close(fd);
		exit(-1);
	}
	//printf("Bind successfully.\n");
	
	int temp;
	//=============================3way==================================
	packet.th_flags=0x02;
	//packet.th_seq=(rand() % 10000);
	packet.th_seq=0;
	packet.th_ack=(rand() % 10000);
	printf("Send a SYN packet to [%s : %d]\n",inet_ntoa(addr_to.sin_addr),addr_to.sin_port);
	sendto(fd,(struct TCPheader*)&packet.th_flags,1,0,(struct sockaddr*)&addr_to,sizeof(addr_to));
	sendto(fd,(struct TCPheader*)&packet.th_seq,32,0,(struct sockaddr*)&addr_to,sizeof(addr_to));
	sendto(fd,(struct TCPheader*)&packet.th_ack,32,0,(struct sockaddr*)&addr_to,sizeof(addr_to));
	
	struct sockaddr_in to;
	socklen_t lenB;
	lenB=sizeof(to);
	
	r=recvfrom(fd,(struct TCPheader*)&packet.th_flags,1,0,(struct sockaddr*)&to,&lenB);
	if (packet.th_flags==0x02 || packet.th_flags==0x10)
	{
		printf("Receive a SYN/ACK packet from [ %s : %d ] \n",inet_ntoa(to.sin_addr),to.sin_port);
		r=recvfrom(fd,(struct TCPheader*)&packet.th_seq,10,0,(struct sockaddr*)&to,&lenB);
		r=recvfrom(fd,(struct TCPheader*)&packet.th_ack,10,0,(struct sockaddr*)&to,&lenB);
		temp = packet.th_seq;
		packet.th_seq = packet.th_ack;
		packet.th_ack = temp;
		printf("\tGet a packet(seq=%d , ack=%d)\n",packet.th_seq,packet.th_ack);
	}

	packet.th_flags=0x10;
	printf("Send an ACK packet to [%s : %d]\n",inet_ntoa(addr_to.sin_addr),addr_to.sin_port);
	sendto(fd,(struct TCPheader*)&packet.th_flags,1,0,(struct sockaddr*)&addr_to,sizeof(addr_to));
	sendto(fd,(struct TCPheader*)&packet.th_seq,32,0,(struct sockaddr*)&addr_to,sizeof(addr_to));
	sendto(fd,(struct TCPheader*)&packet.th_ack,32,0,(struct sockaddr*)&addr_to,sizeof(addr_to));
	printf("Complete three way handshake\n=================\n");
	//=============================3way==================================
	printf("Received a file from [ %s : %d ] \n",inet_ntoa(to.sin_addr),to.sin_port);
	
	double duration=0;
	while(duration < RTT)
	{	
		clock_t start, finish;
		start = clock();
		r=recvfrom(fd,(struct TCPheader*)&packet.th_seq,10,0,(struct sockaddr*)&to,&lenB);
		r=recvfrom(fd,(struct TCPheader*)&packet.th_ack,10,0,(struct sockaddr*)&to,&lenB);
		temp = packet.th_seq;
		packet.th_seq = packet.th_ack;
		packet.th_ack = temp;
		printf("\tGet a packet(seq=%d , ack=%d)\n",packet.th_seq,packet.th_ack);
		usleep(RTT);
		finish = clock();
		duration = ((double)(finish - start) / CLOCKS_PER_SEC)*1000000;	
	}
	printf("File end\n");
	printf("=================\n");
	//=============================4way==================================
	r=recvfrom(fd,(struct TCPheader*)&packet.th_flags,1,0,(struct sockaddr*)&to,&lenB);
	if (packet.th_flags==0x01)
	{
		printf("Receive a FIN packet from [ %s : %d ] \n",inet_ntoa(to.sin_addr),to.sin_port);
		r=recvfrom(fd,(struct TCPheader*)&packet.th_seq,10,0,(struct sockaddr*)&to,&lenB);
		r=recvfrom(fd,(struct TCPheader*)&packet.th_ack,10,0,(struct sockaddr*)&to,&lenB);
		temp = packet.th_seq;
		packet.th_seq = packet.th_ack;
		packet.th_ack = temp;
		printf("\tGet a packet(seq=%d , ack=%d)\n",packet.th_seq,packet.th_ack);
	}

	packet.th_flags=0x10;
	packet.th_seq = packet.th_seq+1;
	printf("Send an ACK packet to [%s : %d]\n",inet_ntoa(addr_to.sin_addr),addr_to.sin_port);
	sendto(fd,(struct TCPheader*)&packet.th_flags,1,0,(struct sockaddr*)&addr_to,sizeof(addr_to));
	sendto(fd,(struct TCPheader*)&packet.th_seq,32,0,(struct sockaddr*)&addr_to,sizeof(addr_to));
	sendto(fd,(struct TCPheader*)&packet.th_ack,32,0,(struct sockaddr*)&addr_to,sizeof(addr_to));

	packet.th_flags=0x01;
	printf("Send a FIN packet to [%s : %d]\n",inet_ntoa(addr_to.sin_addr),addr_to.sin_port);
	sendto(fd,(struct TCPheader*)&packet.th_flags,1,0,(struct sockaddr*)&addr_to,sizeof(addr_to));
	sendto(fd,(struct TCPheader*)&packet.th_seq,32,0,(struct sockaddr*)&addr_to,sizeof(addr_to));
	sendto(fd,(struct TCPheader*)&packet.th_ack,32,0,(struct sockaddr*)&addr_to,sizeof(addr_to));
	
	r=recvfrom(fd,(struct TCPheader*)&packet.th_flags,1,0,(struct sockaddr*)&to,&lenB);
	if (packet.th_flags==0x10)
	{
		printf("Receive an ACK packet from [ %s : %d ] \n",inet_ntoa(to.sin_addr),to.sin_port);
		r=recvfrom(fd,(struct TCPheader*)&packet.th_seq,10,0,(struct sockaddr*)&to,&lenB);
		r=recvfrom(fd,(struct TCPheader*)&packet.th_ack,10,0,(struct sockaddr*)&to,&lenB);
		temp = packet.th_seq;
		packet.th_seq = packet.th_ack;
		packet.th_ack = temp;
		printf("\tGet a packet(seq=%d , ack=%d)\n",packet.th_seq,packet.th_ack);
	}

	printf("Complete four way handshake\n=================\n");
	//=============================4way==================================
	sendto(fd,buf,r,0,(struct sockaddr*)&addr_to,sizeof(addr_to));
	close(fd);
	return 0;
}
