/*
 * Main.c
 * 
 * Created By Randall White
 * Requires SUNDIALS and LaPACK
 * Lawrence Berkeley National Labs 
 */

/* C11 includes */
#include <stdio.h> //standard library
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include <time.h>
#include <stdbool.h>



/* POSIX includes */ 
#include <unistd.h>
#include <errno.h>
#include <fcntl.h> //for file descriptor stuff
#include <ucontext.h> //for context switching
#include <pthread.h> 
#include <sys/types.h>
#include <sys/stat.h>

/* SUNDIALS includes  */ 
//testing with cvode first...
#include <cvode/cvode.h>             /* prototypes for CVODE fcts., consts. */
#include <cvode/cvode_band.h>        /* prototype for CVBand */
#include <nvector/nvector_serial.h>  /* serial N_Vector types, fcts., macros */
#include <sundials/sundials_band.h>  /* definitions of type DlsMat and macros */
#include <sundials/sundials_dense.h> /* definitions DlsMat DENSE_ELEM */
#include <sundials/sundials_types.h> /* definition of type realtype */
//~ #include <arkode/arkode.h>           /* prototypes for ARKODE fcts., consts. */
//~ #include <nvector/nvector_serial.h>  /* serial N_Vector types, fcts., macros */
//~ #include <arkode/arkode_dense.h>     /* prototype for ARKDense */


/* For Portable Coroutine includes */ 
//~ - NOT HERE YET 
//~ #include <pcl.h>



/* For ZeroMQ includes */ 
//~ - NOT HERE YET 
//~ #include <zmq.h>


/* Internal process attributes  */ 
pid_t pid; // this is the pid for our daemon process redundant
long numOfCores; //getting the number of cores 
FILE *mainFile; //main file for writing 

/* Sundials attributes */
N_Vector y = NULL;              /* empty vector for storing solution */
N_Vector y0 = NULL; //initial values.. I think I need this? 
/* Function definitions */ 
static int f(realtype t, N_Vector y, N_Vector ydot, void *user_data); //this is a test right here 


typdef long int vectorVar;

int main(int argc, char **argv)
{
	puts(" Crea Dyanmic Engine ~ Testing "); 				
	/* threading initialization */ 
	
	/*setup stack variables and assign stack or static/global variables */ 
	  realtype dx, dy, reltol, abstol, t, tout, umax;
	  N_Vector u;
	  UserData data;
	  void *cvode_mem;
	  int iout, flag;
	  long int nst;


	/*assign stack and static/global variables */ 
	mainFile = NULL; //main file for the program. using C functions to abstract OS functions. buffering is nice too...

	/* Non portable area  */ 
	numOfCores = sysconf( _SC_NPROCESSORS_ONLN );  //getting number of cpus
	pid = getpid(); //getting the pid of creal	

	/* End of Non portable area  */
	
	/* main processing area */ 




	
	
	
	
	/*End of main processing area */
	
	fclose(mainFile); //make sure to close the main file 
	exit(EXIT_SUCCESS); //gnu
}


/*---- end of file ----*/
