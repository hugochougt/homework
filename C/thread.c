#include<pthread.h>
#include<stdio.h>

int sum;	// the data is shared by the thread(s)
void* runner(void *param);	// the thread

int main()
{
	pthread_t tid;	// the thread idetifier
	pthread_attr_t attr;	//set of thread attributes
	
	if(argc != 2) {
		fprintf(stderr, "usage:a.out<interger value>\n");
		
	}
}
