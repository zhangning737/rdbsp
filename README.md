1. Background
----------------

Rock dynamics has become one of the most important topics in the field of rock mechanics and rock engineering. The spectrum of rock dynamic behavior widely includes phenomena of rockbursting, spalling, popping, collapse, toppling, sliding, and so on, which induced by the stress redistribution and energy release after excavation. Current version of rdbsp arms to simulate the process of displacement field redistribution and stress wave propagation in deep underground rock with finite element method. Forward Euler time integration scheme is adapted in this program to simulate the dynamic procedure . 

2. Functionality
----------------

This explicit dynamic finite element program is utilized to calculate
the deep rock mass deformation, which is written by the c++ language and
calculated using a single integration point block element with eight
nodes. To eliminate the hourglass effect in calculation, the hourglass
resistance, which is perpendicular to the rotation modal of rigid body
and established by Belytschko and Flanagan in 1982, is applied in this
program. The Jaumann derivative is added into the program with the
concern of the effect of the rigid body rotation to solve the difficulty
of the large deformation calculation for the deep rock mass. The program
enables both the static and the dynamic finite element calculation. The
geometric model can be built by the Hypermesh pre-processing software
via the keyword recognition and post-processing interfaces, and the
calculated result can be shown by the two post-processing programs
Tecplot or Paraview.

3. Requirements
---------------

-   System: Linux 2.6+
-   Software enviorment: Intel compiler with MKL, community edition，
    2013+
-   Hardware: Any AMD64 arch platform

4. Installation
---------------

-  Register as an **Open Source Contributors** and download & install community version [**Intel® Parallel Studio XE**](https://software.intel.com/en-us/parallel-studio-xe/choose-download)
-  Make -f Makefile\_LINUX64, generate "rdbsp" binary file
-  Copy to any where you want

5. Usage
-------------

The program is running on command line enviorment. It has three options,
using "-i" defines the name of input file, or you need to type the input
file at terminal(Don\'t do that except debuging, please edit you input
file before runing it.). using "-r" difines the name of status file,
this option is used for restart an analysis. Using "-r" difines the name
of output file\
\
The usage as following:

> usage: cmd \[ -i input file name\] \[-r \] \[-o \]\[?\]

6. Guidelines of coding
------------------------

The structure of this program is shown below. As shown in the figure,
the input file first is interprated by the progam, and initial a class
called \"domain\", which includes data of nodes, elements, and control
variables for solver. During the \"domain\" intiallization, a dynamic
memory management class \"BlockAlloc\" could apply a 4K block when there
is no enough memory for the \"domain\". The memory management unit seems
old style now, we wish we could update to more mordern one then. After
data input, a function \"preProcess\" will be called to remove elements
without material property, generate a map list for elements and nodes,
apply intial stress and boundary condition. Then the main loop \"solve\"
function will be called to solve the problem with a dynamic FEM solver.


The folders contain content shown below:

| Folder            | Functions                                                                                       |
| ----------------- | ----------------------------------------------------------------------------------------------- |
| Documentation     | Documentation of this repository                                                                |
| Driver.d          | Class Domain, including all the data and solving functions of main loop                         |
| Element.d         | Classes of Nodeset, Elementset, Node and Element                                                |
| Material.d        | Classes of Materialset and Material, Material has child class of Elastic and Mohr Coulomb model |
| Parser.d          | lexerl.l defines the grammer of the input file                                                  |
| Solvers.d         | Some header files for solver                                                                    |
| TecplotIO.d       | Header files for Tecplot output                                                                 |
| Tests             | Testing example                                                                                 |
| Timers.d\_LINUX64 | Get system time and static solving time                                                         |
| Utils.d           | Memory managment, cuvre data, reading and wring status file, and some other utilities           |

