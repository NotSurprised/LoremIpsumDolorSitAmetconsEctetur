#include <stdio.h>
#include <unistd.h>
#include <time.h> //time_t time()  clock_t clock()
int main( void )
{
	clock_t start, finish;
	double duration;
	/* 測量一個事件持續的時間*/
	printf( "Time is ");
	start = clock();
	usleep(200);
	finish = clock();
	duration = ((double)(finish - start) / CLOCKS_PER_SEC)*1000000;
	printf( "%f seconds\n", duration );
	return 0;
}



