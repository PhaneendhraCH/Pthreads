#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>	// pthread header
#include <unistd.h>	// header for sleep file
#include <semaphore.h> // semaphore header file

#define Number 10

/*

Compile :

gcc semaphore.c -lpthread -o semaphore 

Creating Object file named  "semaphore"

*/

sem_t semaphore;

void *func(void *ptr){ // subroutine

	sem_wait(&semaphore);   // holds if 0, wait, else enter critical section
				 /* if not 0, permits threads to critical section 
				 and decrement the value S-- */
	sleep(1);
	printf("Im from thread %d\n",*(int*)ptr);
	
	sem_post(&semaphore); // After exiting the thread the, Sempahore value will be 					incremented, S++;
	free(ptr);
}


int main(){

	pthread_t id[Number];
	
	//semaphore holds non integer values
	
	//sem_init(&semaphore,0,2); // Two thread can enter into critical section
	sem_init(&semaphore,0,1); // only one thread can enter into critical section
	
	for (int i=0;i<Number;i++){
		int *a = malloc(sizeof(int));
		*a = i;
		pthread_create(&id[i],NULL,&func,a);
	}
	
	for (int i=0;i<Number;i++){
		pthread_join(id[i],NULL);
		
	}
	sem_destroy(&semaphore);
	return 0;
}
