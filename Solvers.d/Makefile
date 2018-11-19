include ../Main.d/defs


LIB = libsolver.a

OBJS =  $(LIB)(Preconditioner.o) \
	$(LIB)(UFront.o)    $(LIB)(Solver.o) \
	$(LIB)(Rbm.o) $(LIB)(KProject.o) $(LIB)(PCGSolver.o) $(LIB)(dsvdc.o)


$(LIB):  $(OBJS)
#	$(RANLIB) $(LIB)

$(LIB)(UFront.o) : UFront.C UFront.h Rbm.h Solver.h ../Utils.d/dofset.h\
                   ../Math.d/SymFullMatrix.h \
                   ../Math.d/FullSquareMatrix.h

$(LIB)(Solver.o) : Solver.C Solver.h ../Math.d/Vector.h

$(LIB)(PCGSolver.o) : PCGSolver.C PCGSolver.h Rbm.h Preconditioner.h

$(LIB)(Rbm.o) : Rbm.C Rbm.h ../Math.d/matrix.h ../Math.d/Vector.h\
                ../Math.d/VectorSet.h\
                ../Math.d/mathUtility.h ../Math.d/IntFullM.h\
                ../Math.d/SparseMatrix.h\
                ../Utils.d/dofset.h\
                ../Element.d/Element.h 

$(LIB)(Preconditioner.o) : Preconditioner.C Preconditioner.h\
                           ../Math.d/SparseMatrix.h


