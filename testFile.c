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


//Static vars
inline void *ptrMainThread; //for main thread stack

unsigned int mainStack[4]; 

char tempString[256]; //this is here to just make a path for our function in order to run our parse daemon
//~ pid_t crealPid; //this is used to grab the pid of the process
pid_t pid, sid, cpid; // this is the pid for our daemon process redundant
long numOfCores; //getting the number of cores 


//function declarations 
//~ int returnNumberOfCoresOnSystem(void); //this function will return the amount of cores available on the system

int main(int argc, char **argv)
{
	puts("TESTING"); 
	numOfCores = sysconf( _SC_NPROCESSORS_ONLN );  //getting number of cpus
	
	printf("Number of cores : %d \n",numOfCores); //display core count 
	
	pid = getpid(); //getting the pid of creal	
	FILE *outputFP = NULL; //this is to actually write the file
					


	return 0; //bsd compat
} 

