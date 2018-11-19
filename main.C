#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
 


 
//#include <windows.h>
//#include <direct.h>


#include "Driver.d/Domain.h"
#include "Timers.d/Timing.h"
#include "Timers.d/GetTime.h"
#include "Utils.d/Memory.h"
#include "Utils.d/RWStatfile.h"

Domain *domain = new Domain;

extern int getopt(int argc, char *argv[], char *opstring);

extern int yyparse(void);

int main(int argc, char** argv)
{
extern char *optarg;
extern int optind;
fprintf(stderr,"..........................................................................\n");
fprintf(stderr,"..........................................................................\n");
fprintf(stderr,"..........................................................................\n");
fprintf(stderr,"...     Writen By Zhang Ning Email: zhangning@njust.edu.cn             ...\n");
fprintf(stderr,"..........................................................................\n");
fprintf(stderr,"..........................................................................\n");
fprintf(stderr,"..........................................................................\n");

    domain->iniversion();
    // regitratation
    //program start
 double initTime = getTime();
 int c;
 // system("rm *.csv");
 // system("rm *.plt");
 //system("rm *.vtk");
 //system("rm *.his");
 //system("rm tp1*");
 // Process command line arguments

 
 int errflg = 0;
 int computflg = 0;
 char *inpfile = NULL;
 char *resfile = NULL;
 char *outfile = NULL;
 
 fprintf(stderr,"\nRunning Finite Element Computation Programme\n");
 fprintf(stderr,"Writen by Zhang Ning @NJUST\n");
 while ((c = getopt(argc, argv, "r:i:o:")) != EOF)
      switch (c) {
      case 'i':
          inpfile = optarg;
          computflg += 1;
          fprintf(stderr, "Input File Name = %s \n", inpfile);
	 break;
      case 'r':
          resfile = optarg;
          computflg += 3;
          fprintf(stderr, "Restart Filename = %s \n", resfile);
          domain->setrestartflg();
         break;
      case 'o':
          outfile = optarg;
          fprintf(stderr, "Restart Filename = %s \n", resfile);
          domain->setoutfile(outfile);
          break;
      case '?': 
          errflg++;
      }
 if (errflg){
     fprintf(stderr, "usage: cmd [-r <restart filename] [-i input file name]");
     exit(2);
 }

 
 FILE *nin;
 if((computflg == 4)||(computflg == 3)) {
     

     readstatfile(resfile,domain);
     domain->userdel();
 
 }
 // Open input file
 if(inpfile) {
   nin = freopen(inpfile,"r",stdin);
   if(nin == 0) {
     fprintf(stderr,"ERROR: Could not open input file: %s\n",argv[argc-1]);
     exit(-1);
   }
 }

 char buf[256];
 getcwd(buf,sizeof(buf));
 //fprintf(stderr,"current working directory : %s\n",buf);
 char infilepath[256];
 sprintf(infilepath,"%s\/%s",buf,inpfile);
 // printf("%s",infilepath);
 domain->setinfilepath(infilepath);

 //

 MatrixTimers &times = domain->getTimers();
 // Read input file and time reading
 fprintf(stderr,"Start Reading Input File\n");
startTimerMemory(times.readTime, times.memoryParse);
 int error = yyparse();
stopTimerMemory(times.readTime, times.memoryParse);
 


 // Check if Input file had any errors
 if(error) {
   fprintf(stderr,"ERROR: Input file contained errors. Aborting ... \n");
   exit(error);
 }

 fclose(nin);

 startTimerMemory( times.setUpDataTime, times.memorySetUp );
 if(computflg == 1){
     domain->setUpData();
     domain->preProcess();
 }
 else if(computflg == 4){
     domain->setUpData();
     domain->preProcess();  
 }
 stopTimerMemory( times.setUpDataTime, times.memorySetUp );


  long long totalMemoryUsed = 0;
  switch(domain->probType()) {
           case SolverInfo::Dynamic: {
               
                domain->solve();
                totalMemoryUsed = memoryUsed();
           }
               break;
  }
  
  // End simulation, print total time and memory used
 fprintf(stderr,"Total Time  : %13.3f s \n",
         (getTime() - initTime));
 fprintf(stderr,"Total Memory: %13.3f Mb \n",
          totalMemoryUsed/(1024.0*1024.0));
 fprintf(stderr," \n");
 int xxxxx =1;
 return 0;
}

