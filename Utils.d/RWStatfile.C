#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Driver.d/Domain.h"
#include "../Utils.d/RWStatfile.h"

int
readstatfile(char *res, Domain* dm){
    FILE *rin;
         rin = fopen(res,"rb");
     if(rin == 0 ){
         fprintf(stderr, "ERROR: Could not open output file: %s\n", res);
         exit(-1);
     }

     int i,j,k;
     char* strptr = new char[512];
     int* ntemp = new int[49];
     double* dtemp = new double[49];
     
     fread(strptr,sizeof(char),256, rin);

     time_t *tp = new time_t;
     fread(tp, sizeof(time_t), 1 ,rin);

     fread(strptr, sizeof(char), 5, rin);

     fread(dtemp,sizeof(double), 1 ,rin);
     dm->SetCurrentTime(dtemp[0]);

     fread(ntemp, sizeof(int) , 1, rin);
     //     dm->SetNodeNum(ntemp[0]);
     if(ntemp[0] != 0 ){
         dm->setrestartflg();
     }
     
     fread(ntemp, sizeof(int) , 1, rin);
     //     dm->SetNodeNum(ntemp[0]);
     int readnodenum = ntemp[0];
     
     fread(ntemp, sizeof(int) , 1 ,rin);
     //dm->SetElemNum(ntemp[0]);
     int readelemnum = ntemp[0];

	 
     
     fread(ntemp, sizeof(int) , 1 , rin);
     dm->solinfo().setProbType(ntemp[0]);

     fread(ntemp,sizeof(int) , 1, rin);
     fread(dtemp,sizeof(double) , 4, rin);
     dm->ResetSolver(ntemp[0], dtemp);

     fread(ntemp, sizeof(int) , 1 , rin);
     int readhisnum = ntemp[0];
     dm->sethisdata(ntemp[0]);

     fread(ntemp, sizeof(int), 1 , rin);
     if(ntemp[0] == 1) {
         dm->setlarge();
     }

     fread(ntemp, sizeof(int), 1, rin);
     fread(dtemp, sizeof(double), 1, rin);
     dm->sethourglass(ntemp[0],dtemp[0]);

     fread(dtemp, sizeof(double), 3, rin);
     dm->setgrav(dtemp[0],dtemp[1],dtemp[2]);
     
     fread(ntemp, sizeof(int),2,rin);
     fread(dtemp, sizeof(double), 1, rin);     


     if(ntemp[1] == 0){
         dm->setointer(ntemp[0],dtemp[0]);
     }
     else{
         dm->setointer(ntemp[0],dtemp[1]);
     }

     fread(ntemp, sizeof(int), 1, rin);
     int readnout = ntemp[0];

     fread(ntemp, sizeof(int), readnout,rin);
     for(i = 0; i < readnout; ++i){
         dm->addnout(ntemp[i]);
     }

     fread(ntemp, sizeof(int), 1, rin);
     int readeout = ntemp[0];

     fread(ntemp, sizeof(int), readeout,rin);
     for(i = 0; i < readeout; ++i){
         dm->addeout(ntemp[i]);
     }


     //read his
     fread(dtemp, sizeof(double), 1, rin);     
     fread(ntemp, sizeof(int),1,rin);

     if(dtemp[0] ==0.0){
         dm->sethisointer(ntemp[0]);
     }
     else{
         dm->sethisointer(dtemp[0]);
     }

     fread(ntemp, sizeof(int), 1, rin);
     readnout = ntemp[0];

     fread(ntemp, sizeof(int), readnout,rin);
     for(i = 0; i < readnout; ++i){
         dm->addhisnode(ntemp[i]);
     }

     fread(ntemp, sizeof(int), 1, rin);
     readeout = ntemp[0];

     fread(ntemp, sizeof(int), readeout,rin);
     for(i = 0; i < readeout; ++i){
         dm->addhiselem(ntemp[i]);
     }

     //fdafdsa
     fread(ntemp, sizeof(int), 1, rin);
     int readmnum = ntemp[0];
     for(i =0 ; i < readmnum; ++i){
       fread(ntemp, sizeof(int), 3, rin);
       fread(dtemp, sizeof(double), ntemp[2], rin);
       dm->addMat(ntemp[0], ntemp[1], ntemp[2], dtemp);
     }
     
     fread(ntemp, sizeof(int), 1, rin);
     int readcnum = ntemp[0];

     for(i = 0 ; i < readcnum; ++i ){
         fread(ntemp,sizeof(int),2,rin);
         fread(dtemp,sizeof(double) , 2*ntemp[1], rin);

         dm->addCurve(ntemp[0], 2*ntemp[1], dtemp);
         
     }

      fread(ntemp,sizeof(int),readcnum, rin);
      dm->ReadCDerflg(ntemp);


      // read pressure
     fread(ntemp, sizeof(int), 1, rin);
     int readpnum = ntemp[0];
     BPress bp;
     for(i = 0 ; i < readpnum; ++i ){
         fread(ntemp,sizeof(int),1,rin);
         bp.cnum = ntemp[0];

         
         fread(dtemp,sizeof(double) , 1, rin);
         bp.value = dtemp[0];         

         fread(ntemp,sizeof(int) , 4, rin);
         for(j = 0; j < 4 ; ++j){
             bp.nodelist[j] = ntemp[j];  
         }



         dm->setpress(bp);
         
     }     
      
      
      for(i = 0 ; i < readnodenum; ++i){
          fread(ntemp,sizeof(int), 1 , rin);
          fread(dtemp,sizeof(double), 3,rin);
          dm->addNode(ntemp[0],dtemp);
      }

      for(i=0; i < readnodenum; ++i){

          fread(dtemp,sizeof(double),19,rin);
          
          fread(ntemp,sizeof(int),10,rin);

          dm->ResetNData(dtemp,ntemp, i);
 
      }

      int *ntemp1 = new int[256];
      for(i =0; i< readelemnum; ++i){
          fread(ntemp1,sizeof(int),2,rin);
          if(ntemp1[1] == 1) {
              fread(ntemp,sizeof(int), 8 ,rin);
          dm->addElem(ntemp1[0], ntemp1[1], 8 , ntemp);              
          }

      }

      for(i = 0 ; i < readelemnum; ++i){
          switch(ntemp1[1]){
          case 1:
              fread(dtemp, sizeof(double), 12+readhisnum , rin);
              break;
          default:
              return 0;
          }

          dm->ResetEData(dtemp, readhisnum, i);
          
      }

      
      fread(ntemp, sizeof(int), 1 ,rin);
      int readanum = ntemp[0];
      // reand att
      for(i = 0 ; i < readanum; ++i){
          fread(ntemp,sizeof(int), 2, rin);
          dm->setatt(ntemp[0],ntemp[1]);
      }
      
      fread(ntemp, sizeof(int), 1 ,rin);
      readanum = ntemp[0];

      for(i = 0 ; i < readanum; ++i){
          fread(ntemp,sizeof(int), 2, rin);
          dm->setpatt(ntemp[0],ntemp[1]);
      }
      //read part
      fread(ntemp, sizeof(int), 1 ,rin);
      readpnum = ntemp[0];

      int *partnum;
      for(i = 0; i < readpnum; ++i){
          fread(ntemp, sizeof(int), 3 ,rin);
          int length = ntemp[0];
          int partdenum = ntemp[1];
          int partdetype = ntemp[2];
          partnum = new int[length];
          fread(partnum, sizeof(int), length,rin);  
          
          dm->addPart(partdenum, partdetype, length,partnum);
      }


      
     
     fclose(rin);
     return 0;
}
