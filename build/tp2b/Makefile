include Filelist
include Dependencies

NAME = tp2b

PROGRAM = $(NAME).exe

FC = gcc
FFLAGS = -c -g -Wall -std=c99 -I ../../headers
LD = gcc
LDFLAGS = -lm -g 

VPATH = ../../TP1 ../../TP2a ../../TP2b 

$(PROGRAM): $(OBJECTS)
			$(LD) $(LDFLAGS) -o $@ $^

.PHONY: clean

clean:
		rm -f *.o *.exe


%.o:%.c $(DEPS)
		$(FC) $(FFLAGS) $<

