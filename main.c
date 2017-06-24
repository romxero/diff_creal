/*
 * Main.c
 * 
 * Created By Randall White
 * Requires SUNDIALS and LaPACK
 * Lawrence Berkeley National Labs 
 */

/* C11 includes */
#include <stdio.h>		//standard library
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

/* POSIX includes */
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>		//for file descriptor stuff
#include <ucontext.h>		//for context switching
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>

/* SUNDIALS includes  */
//testing with cvode first...
#include <cvode/cvode.h>	/* prototypes for CVODE fcts., consts. */
#include <cvode/cvode_band.h>	/* prototype for CVBand */
#include <nvector/nvector_serial.h>	/* serial N_Vector types, fcts., macros */
#include <sundials/sundials_band.h>	/* definitions of type DlsMat and macros */
#include <sundials/sundials_dense.h>	/* definitions DlsMat DENSE_ELEM */
#include <sundials/sundials_types.h>	/* definition of type realtype */
//~ #include <arkode/arkode.h>           /* prototypes for ARKODE fcts., consts. */
//~ #include <nvector/nvector_serial.h>  /* serial N_Vector types, fcts., macros */
//~ #include <arkode/arkode_dense.h>     /* prototype for ARKDense */

/*MACROS */

//~ //taken from CVODE library 
//~ #define ATOL RCONST(1.0e-6)
//~ #define RTOL RCONST(0.0)

//~ #define ZERO   RCONST(0.0)
//~ #define ONE    RCONST(1.0)
//~ #define TWO    RCONST(2.0)
//~ #define THIRTY RCONST(30.0)
/* Shared Problem Constants */

#define ATOL RCONST(1.0e-6)
#define RTOL RCONST(0.0)

#define ZERO   RCONST(0.0)
#define ONE    RCONST(1.0)
#define TWO    RCONST(2.0)
#define THIRTY RCONST(30.0)

/* Problem #1 Constants */

#define P1_NEQ        2
#define P1_ETA        RCONST(3.0)
#define P1_NOUT       4
#define P1_T0         RCONST(0.0)
#define P1_T1         RCONST(1.39283880203)
#define P1_DTOUT      RCONST(2.214773875)
#define P1_TOL_FACTOR RCONST(1.0e4)

/* Problem #2 Constants */

#define P2_MESHX      5
#define P2_MESHY      5
#define P2_NEQ        P2_MESHX*P2_MESHY
#define P2_ALPH1      RCONST(1.0)
#define P2_ALPH2      RCONST(1.0)
#define P2_NOUT       5
#define P2_ML         5
#define P2_MU         0
#define P2_T0         RCONST(0.0)
#define P2_T1         RCONST(0.01)
#define P2_TOUT_MULT  RCONST(10.0)
#define P2_TOL_FACTOR RCONST(1.0e3)

/* Linear Solver Options */

//not sure what these enums are for but ok
enum { FUNC, DENSE_USER, DENSE_DQ, DIAG, BAND_USER, BAND_DQ };

/* For Portable Coroutine includes */
//~ - NOT HERE YET 
//~ #include <pcl.h>

/* For ZeroMQ includes */
//~ - NOT HERE YET 
//~ #include <zmq.h>

/* Internal process attributes  */
pid_t pid;			// this is the pid for our daemon process redundant
long numOfCores;		//getting the number of cores 
FILE *mainFile;			//main file for writing 

/* Sundials attributes */
//~ N_Vector y = NULL;              /* empty vector for storing solution */
//~ N_Vector y0 = NULL; //initial values.. I think I need this? 
/* Function definitions */
static int f(realtype t, N_Vector y, N_Vector ydot, void *user_data);	//this is a test right here 

static int testFunction(realtype t, N_Vector y, N_Vector ydot, void *user_data);	//this is a test right here 

typedef long int vectorVar;
typedef long long longVectorVar;	//long long datatype for 64-bit usage 

/* defined structures */
struct testStructure {
	vectorVar v1;
	vectorVar v0;
	bool isTrue;
};

//~ typedef struct *testStructure testStructurePtr; //this is just to make assignments easier 

int main(int argc, char **argv)
{
	puts(" Crea Dyanmic Engine ~ Testing ");
	/* threading initialization */

	/*setup stack variables and assign stack or static/global variables */
	realtype dx, dy, reltol, abstol, t, tout, umax, nuY, nuYDot;
	N_Vector u;
	//~ UserData data;
	void *cvode_mem;
	int iout, flag;
	long int nst;
	struct testStructure makeStruct; 
	//~ testFunction(t, nuY, nuYDot, (void *) makeStruct );	//just like posix threads, make sure to cast as a voided pointer  

	/*assign stack and static/global variables */
	//~ mainFile = NULL; //main file for the program. using C functions to abstract OS functions. buffering is nice too...

	/* Non portable area  */
	numOfCores = sysconf(_SC_NPROCESSORS_ONLN);	//getting number of cpus
	pid = getpid();		//getting the pid of creal      

	/* End of Non portable area  */

	/* main processing area */

	//~ CVodeInit(); //initialize CVODE 

	/*End of main processing area */

	//~ fclose(mainFile); //make sure to close the main file 
	exit(EXIT_SUCCESS);	//gnu
}

/*---- end of file ----*/
