*FIXNODE
       10                   1         1         1 
       11                   1         1         1 
       14                   1         1         1 
       15                   1         1         1 
       12                   1         1        0 
       13                   1         1        0 
       16                   1         1        0 
       17                   1         1        0 
*ELEMENT, type = c3d8r, epart = 1
       1        10      13      12      11      14      17      16      15
*NODE
      10       0.5000000           0.000       1.0000000
      11           0.000           0.000       1.0000000
      12           0.000           0.000       0.5000000
      13       0.5000000           0.000       0.5000000
      14       0.5000000       0.5000000       1.0000000
      15           0.000       0.5000000       1.0000000
      16           0.000       0.5000000       0.5000000
      17       0.5000000       0.5000000       0.5000000
*DISPLACEMENT
         12        3                  1       1.0
         13        3                  1       1.0 
         16        3                  1       1.0 
         17        3                  1       1.0 
*CURVE, id = 1
0.0  0.0 
125   0.125
*CURVE,id =2
   0.0 0.0 
   5     0.5  
   10    1.0 
   15    1.0 
*Solver
*dynamic
*TERMINATION
125
*Timestep, type = fixed
1.e-2   
*hourglass
1 0.1
*HISTORY
21
*Jauma
*ATTRIBUTE
1  1
*HISOUTPUT
0.2
*hisnode
12
%*debug
*OUTPUT
1 1.0
nout_inf nout_disp nout_v nout_a nout_extf
eout_stress eout_strain 
%eout_history
%*GRAVITY
%0.0 .0 10.0 
*Material
1      1    2600    20.0e9   0.3 
%LOCALDAMPING
%0.8
*END
