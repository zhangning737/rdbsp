include defs

# always change BASEDIR to your particular directory
include basedir

LIBS = Parser.d/libparser.a\
       Driver.d/libdriver.a\
       Element.d/libele.a\
       Utils.d/libutility.a\
       Timers.d_LINUX64/libtimer.a\
       Material.d/libmat.a\
       tecio64.a Math.d/libmath.a


# Compiler Flags necessary for templates


# Executables

rdbsp: main.o $(LIBS) $(ADDLIBS)
	$(CXX) -o rdbsp $(CXXFLAGS) main.o $(LIBS)

# command for creating the file basedir for a user
Makefile::
	echo BASEDIR = `pwd` > basedir

# command to make a compressed (gzip) tar file of the FEM code
tarfile::
	tar -cvf ../rdbsp.tar . ; gzip ../rdbsp.tar;

	#echo Making miniFEM executable;
all::
	\rm */*.a */*/*.a; make rdbsp;
clean::
	\rm -r *.o ii_files/ */ii_files/ */*/ii_files/;

Driver.d/libdriver.a::
	(cd Driver.d  ; make)

Element.d/libele.a::
	(cd Element.d ; make )

Parser.d/libparser.a::
	(cd Parser.d ; make)

Timers.d_LINUX64/libtimer.a::
	(cd Timers.d_LINUX64; $(MAKE) )

Utils.d/libutility.a::
	(cd Utils.d; $(MAKE) )

Material.d/libmat.a::
	(cd Material.d; $(MAKE) )


Math.d/libmath.a::
	(cd Math.d; $(MAKE) )
