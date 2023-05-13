include Filelist
include Dependencies

NAME = tp5_plot

PROGRAM = $(NAME).exe

FC = gcc
FFLAGS = -c -g -Wall -std=c99 -I ../../headers
FORTRAN_FC = gfortran
FORTRAN_FLAGS = -c -g
LD = gcc
LDFLAGS = -lm -g -lgfortran -no-pie

VPATH = ../../TP1 ../../TP2a ../../TP2b ../../TP3 ../../TP4 ../../TP5 ../../Utility ../../Fortran

$(PROGRAM): $(OBJECTS) $(FORTRAN_OBJECTS) dmoapr.o
			$(LD) $(LDFLAGS) -o $@ $^

.PHONY: clean

clean:
		rm -f *.o *.exe
		cp ../../TP5/dmoapr.o dmoapr.o
		find -name 'fort*[0-9]' -delete


%.o:%.c $(DEPS)
		$(FC) $(FFLAGS) $<

%.o:%.f $(DEPS)
		$(FORTRAN_FC) $(FORTRAN_FLAGS) $<
