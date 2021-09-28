#include <stdio.h>	 // input/output lib
#include <pthread.h>    // User Space Thread
#include <unistd.h>     // used for sleep function

void *my_thread(void *ptr){

	pthread_detach(pthread_self());  // detaching the thread with itself
	printf("Enter in thread function\n");
	pthread_exit(NULL); // returning NULL to main func where it got invoked.
	//return 0;
}

int main(){
	
	pthread_t tid;
	int ret,var;
	void *rval;
	/*int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);*/
    
        
	ret = pthread_create(&tid,NULL,&my_thread,NULL);
	//ret = pthread_create(&tid,NULL,&my_thread,&var);
	if (ret!=0){
		printf("Thread in not created\n");
		return -1;
	}
	//sleep(1);
	
	printf("Im in main func\n");
	//pthread_join(tid,NULL);
	printf("Back to main function\n");
	pthread_exit(NULL);
	
	return 0;
}
