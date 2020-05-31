#include <stdio.h>
#include <pthread.h>

void *writer(void *c);
void *reader(void *c);

int main(void)
{
	// run defined functions in sperate threads

	// thread identifiers
	pthread_t thread_id_1, thread_id_2;

	// create a new thread
	pthread_create(&thread_id_1, NULL, &writer, NULL);
	pthread_create(&thread_id_2, NULL, &reader, NULL);

	// run with main thread
	pthread_join(thread_id_1, NULL);
	pthread_join(thread_id_2, NULL);
	return 0;
}

void *writer(void *c)
{
	// run with first thread
	printf("I'm writing from first thread for no reason!\n");
}

void *reader(void *c)
{
	// run with second thread
	int num0, num1;

	float average;

	printf("Enter two number to get their average!\n");

	scanf("%d", &num0);
	scanf("%d", &num1);

	average = (num0 + num1) / 2.0;

	printf("I'm in second thread and the average is: %f!\n", average);
}
