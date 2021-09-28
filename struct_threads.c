#include <stdio.h>	 // input/output lib
#include <stdlib.h>
#include <pthread.h>    // User Space Thread
#include <unistd.h>     // used for sleep function

/*

As we are not using any synchrnization techniques it is leading to Race Condition.

Compile :

gcc struct_threads.c -lpthread -o struct_threads 

Creating Object file named  "struct_threads"
*/

struct person{
	int age;
	char gender;
}*p;

void *my_thread(void *ptr){

	p = (struct person *)ptr;
	
	printf("Enter in thread function and age gender = %d and %c\n",p->age,p->gender);
	
	pthread_exit(NULL); // returning NULL to main func where it got invoked.
}

int main(){
	
	pthread_t tid;
	int ret;
	
	struct person P1 = {20,'M'};  // creating structure instance
	
	/*int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);*/
        
	
	ret = pthread_create(&tid,NULL,&my_thread,&P1);
	if (ret!=0){
		printf("Thread in not created\n");
		return -1;
	}
	//sleep(1);
	
	printf("Im in main func\n");
	pthread_join(tid,NULL);
	printf("Back to main function \n");
	
	return 0;
}
