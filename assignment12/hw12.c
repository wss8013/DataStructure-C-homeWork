// name: Shasha Wang
// email: wang.shas@northeastern.edu
// Compile with: mac M1
//
// gcc -lpthread hw12.c -o hw12
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 100
// NOTE se are going to adapt the 100 thread code
// by making the array bigger
// and spawning off 4 groups of 100 threads

// shared variable
int counter = 0;

// thread to be executed - unspecified variable arguments
void* thread1 (void* vargp) {
  // add 1 to counter
  counter = counter +1;
  return NULL;
}

void* thread2 (void* vargp) {
  // add 5 to counter
  counter = counter + 5;
  return NULL;
  // *** YOUR CODE GOES HERE ***
}

void* thread3 (void* vargp) {
  // subtract 2 from counter
  counter = counter -2;
  return NULL;
  // *** YOUR CODE GOES HERE ***
}

void* thread4 (void* vargp) {
  // subtract 10 from counter
  counter = counter - 10;
  return NULL;
  // *** YOUR CODE GOES HERE ***
}

int main() {
  // array to keep Pthread IDs of created threads
  pthread_t tid[NTHREADS*4];
  int i;

  printf("Counter starts at %d\n", counter);
  
  // create and run the thread
  for (i=0; i < NTHREADS; ++i){
    // create the first 100 threads using thread1 code
    pthread_create(&(tid[i]), NULL, thread1, NULL);

    // now create the 2nd, 3rd, 4th group of 100 threads
     pthread_create(&(tid[100+i]), NULL, thread2, NULL);
     pthread_create(&(tid[200+i]), NULL, thread3, NULL);
     pthread_create(&(tid[300+i]), NULL, thread4, NULL);
    
    // *** YOUR CODE GOES HERE ***
  }

  //wait until ALL 400 threads are done
  for (i=0; i < NTHREADS*4; ++i){
    pthread_join(tid[i], NULL);
  }

  printf("Counter ends at %d\n", counter);

  return 0;
}
