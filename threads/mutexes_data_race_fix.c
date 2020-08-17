#include <stdio.h>
#include <stdlib.h>
// The POSIX standard header for using pthread library
#include <pthread.h>

// The mutex object used to synchronize the access to
// the shared state.
//
//  Can use spin instead of mutex
// for busy-wait instead of sleeping mode
pthread_mutex_t mtx;
// pthread_spin_t spn;

void* thread_body_1(void* arg) {
	int* shared_var_ptr = (int*)arg;

	// Critical section
	pthread_mutex_lock(&mtx);
	// pthread_spin_lock(&spn);

	(*shared_var_ptr)++;
	printf("%d\n", *shared_var_ptr);

	pthread_mutex_unlock(&mtx);
	// pthread_spin_unlock(&spn);

	return NULL;
}

void* thread_body_2(void* arg) {
	int* shared_var_ptr = (int*)arg;

	// Critical section
	pthread_mutex_lock(&mtx);
	// pthread_spin_lock(&spn);

	*shared_var_ptr += 2;
	printf("%d\n", *shared_var_ptr);

	pthread_mutex_unlock(&mtx);
	// pthread_spin_unlock(&spn);

	return NULL;
}
int main(int argc, char** argv) {
	// The shared variable
	int shared_var = 0;

	// The thread handlers
	pthread_t thread1;
	pthread_t thread2;

	// Initialize the mutex and its underlying resources
	pthread_mutex_init(&mtx, NULL);
	// pthread_spin_init(&spn, NULL);

	// Create new threads
	int result1 = pthread_create(&thread1, NULL, thread_body_1, &shared_var);
	int result2 = pthread_create(&thread2, NULL, thread_body_2, &shared_var);

	if (result1 || result2) {
		printf("The threads could not be created.\n");
		exit(1);
	}

	// Wait for the threads to finish
	result1 = pthread_join(thread1, NULL);
	result2 = pthread_join(thread2, NULL);

	if (result1 || result2) {
		printf("The threads could not be joined.\n");
		exit(2);
	}

	pthread_mutex_destroy(&mtx);
	// pthread_spin_destroy(&spn);

	return 0;
}
