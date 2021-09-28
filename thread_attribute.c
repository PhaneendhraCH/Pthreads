#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*

As we are not using any synchrnization techniques it is leading to Race Condition.

Compile :

gcc thread_attribute.c -lpthread -o  thread_attribute

Creating Object file named  "thread_attribute"
*/

void *my_thread(void *p){

	printf("Nothing present here \n");
	//pthread_exit(NULL);
}

int main(){

int ret,s,detach_state;
pthread_t tid;  	// thread id
size_t stacksize;	// stacksize

pthread_attr_t attr;	// pthread attribute instance -> attr

pthread_attr_init(&attr); // initialising attribute -> attrs

pthread_attr_getstacksize(&attr,&stacksize); // get stacksize 
printf("Current stack size %d\n",stacksize); // print stack size

pthread_attr_setstacksize(&attr,10000000);   // set new stack size 	

pthread_attr_getstacksize(&attr,&stacksize); // get stacksize  after setting a new one
printf("New stack size %d\n",stacksize);	// print stack size

s = pthread_attr_setdetachstate(&attr,1); // 1=detach, 0=join

s = pthread_attr_getdetachstate(&attr, &detach_state); // get detachstate

ret = pthread_create(&tid,&attr,&my_thread,NULL); // create a thread
printf("im in main func\n");
pthread_exit(NULL);		// exit thread

return 0;
}
