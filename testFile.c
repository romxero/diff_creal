#include <stdio.h> //standard library
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h> //for file descriptor stuff

//threading 
//~ #include "zmq.h" // zeromq library 
//~ #include <omp.h> //openmp
#include "npth.h" //main threading model used in this application 
#include <fcntl.h> 
#include <math.h> 
#include <pthread.h> 



//Static vars
//~ inline void *ptrMainThread; //for main thread stack

unsigned int mainStack[4]; 

char tempString[256]; //this is here to just make a path for our function in order to run our parse daemon
//~ pid_t crealPid; //this is used to grab the pid of the process
pid_t pid, sid, cpid; // this is the pid for our daemon process redundant
long numOfCores; //getting the number of cores 


//function declarations 
//~ int returnNumberOfCoresOnSystem(void); //this function will return the amount of cores available on the system
static int createThreads(int i,int state); 
int main(int argc, char **argv)
{

	npth_init(); //init threading 
	
	numOfCores = sysconf( _SC_NPROCESSORS_ONLN );  //getting number of cpus
	
	printf("Number of cores : %d \n",numOfCores); //display core count 
	
	pid = getpid(); //getting the pid of creal	
	uint corePids[numOfCores]; //an array for number of cores 
	int forkReturnVal = 0;
	uint forkCounter = 0; 
	puts("main Thread"); 
	
		for (forkCounter = 0; forkCounter < numOfCores; forkCounter++) //the main thread counts as one in set so: numOfCores - 1 gives actual numbers to fork
		{
			forkReturnVal = fork();// != 0
			corePids[forkCounter] = forkReturnVal; //adding the values here

			
		}
	
			if (forkReturnVal == 0)
			{
					corePids[forkCounter] = forkReturnVal; //adding the values here
					goto PARENT; 
			} 
			else
			{
				//~ printf("core : %d \n",getpid()); //display core count 
				goto END;
			}
	
		PARENT:
	
		for (forkCounter = 0; forkCounter < numOfCores; forkCounter++) //the main thread counts as one in set so: numOfCores - 1 gives actual numbers to fork
		{

				
						printf("core : %d \n",corePids[forkCounter]); //display core count 

	
		}

	//~ if (getpid() != pid)
	//~ {
						
						
		//~ //run the parsing program right here
	//~ }
	
	
	puts("TESTING"); 				
END:
	exit(EXIT_SUCCESS);	//not fully portable
} 

static int createThreads(int i, int state)
{
	if ( i != state)
	{
		++i;
		printf("core : %d \n",i); //display core count 
	
		
	}
		
	
} 


