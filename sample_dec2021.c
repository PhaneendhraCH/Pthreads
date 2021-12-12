#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>


/*

Compile : gcc sample_dec2021.c -lpthread -o return

*/

void *func(void *ptr){
	
	char *p = (char *)ptr;
	
	printf("Hello there im in func %s\n",p);
	
	return (void*)p;	//--> returning string
	//return (void*)10;  --> returning integer
}


int main(){

	pthread_t tid;
	int val=15;
	void *c;
	
	char str[500]="Hello there\0";

	if(pthread_create(&tid,NULL,&func,&str))
	{
		printf("Thread wasnt created\n");
		return -1;
	}
	
	printf("I am in main function\n");
	pthread_join(tid,&c);

	printf("Return Value is  : %s\n",(char*)c);

	return 0;
}



