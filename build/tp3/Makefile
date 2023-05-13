include Filelist
include Dependencies

FORTRAN_SOURCES = affsmd.f assmat.f
FORTRAN_OBJECTS = $(FORTRAN_SOURCES:.f=.o)

NAME = tp3

PROGRAM = $(NAME).exe

FC = gcc
FFLAGS = -c -g -Wall -std=c99 -I ../../headers
FORTRAN_FC = gfortran
FORTRAN_FLAGS = -c
LD = gcc
LDFLAGS = -lm -g -lgfortran

VPATH = ../../TP1 ../../TP2a ../../TP2b ../../TP3

$(PROGRAM): $(OBJECTS) $(FORTRAN_OBJECTS)
			$(LD) $(LDFLAGS) -o $@ $^

.PHONY: clean

clean:
		rm -f *.o *.exe


%.o:%.c $(DEPS)
		$(FC) $(FFLAGS) $<

%.o:%.f $(DEPS)
		$(FORTRAN_FC) $(FORTRAN_FLAGS) $<
