// Shasha Wang
// wang.shas@northeastern.edu
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
pthread_mutex_t chopstick[5];//lock variable

// Thread to be executed
void *philosopher(void *x)
{
 //Treat variable x as a pointer to an int and then extract the value into n
    int* a=(int*)x;
    int n=*a;
    printf("Philosopher %d is thinking\n",n);
    int left = n % 5;
    int right = (n+1 % 5);
    pthread_mutex_lock(&chopstick[left]);
    pthread_mutex_lock(&chopstick[right]);
    printf("Philosopher %d is eating using chopstick[%d] and chopstick[%d].\n",n,left,right );
    sleep(1);
    pthread_mutex_unlock(&chopstick[left]);
    pthread_mutex_unlock(&chopstick[right]);
    printf("Philosopher %d finished eating.\n",n);

        /*-----Insert your code here----*/

    return NULL;
        
}

/*------------ Main Program---------*/
int main()
{

  pthread_t threads[5];
  int i,val[5];
//initializing the mutex
  for (i=0;i<5;i++){
    pthread_mutex_init(&chopstick[i],NULL);
  }
    
//create and run the thread
  for (i=0;i<5;i++){
      val[i]=i;
      pthread_create(&threads[i],NULL,(void*)philosopher,&val[i]);
  }  
    
//wait until all the threads are done
   for(i=0;i<5;i++){
       pthread_join(threads[i],NULL);
  }
    
// Destroying the mutex
   for(i=0;i<5;i++){
     pthread_mutex_destroy(&chopstick[i]);
   }
    
    return 0;
}
