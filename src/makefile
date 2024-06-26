# set the C compiler, for C++ use g++
# use this setting on most sane machines
CC = gcc

# use this line on the engin linux machines
# CC = gcc296

# set the path to the include directory
INCDIR =../include

# set the flags for the C and C++ compiler to give lots of warnings
CFLAGS = -I$(INCDIR) -I/opt/local/include -O2 -Wall -Wstrict-prototypes -Wnested-externs -Wmissing-prototypes -Wmissing-declarations -g
CPPFLAGS = $(CFLAGS)

# path to the object file directory
ODIR = obj

# path to the lib directory
LIBDIR =../lib

# path to the bin directory
BINDIR =../bin

# libraries to include
LIBS = -lm -lgraphics
LFLAGS = -L$(LIBDIR) -L/opt/local/lib

# put all of the relevant include files here
_DEPS = ppmIO.h image.h graphics.h polygon.h 

# convert them to point to the right place
DEPS = $(patsubst %,$(INCDIR)/%,$(_DEPS))

# put a list of the executables here
EXECUTABLES = test4a triangle test4b polyspeed test4c test4c-loop car test4a_gif

# put a list of all the object files here for all executables (with .o endings)
_OBJ = test4a.o triangle.o test4b.o polyspeed.o test4c.o test4c-loop.o car.o test4a_gif.o

# convert them to point to the right place
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# patterns for compiling source code
# $< is the file that caused the action to occur
$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: %.C $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


all:
	for i in $(EXECUTABLES); do (make $$i) ; done


# put the specific executable rules here
test4a: $(ODIR)/test4a.o
	$(CC) -o $(BINDIR)/$@ $^ $(LFLAGS) $(LIBS)
triangle: $(ODIR)/triangle.o
	$(CC) -o $(BINDIR)/$@ $^ $(LFLAGS) $(LIBS)
test4b: $(ODIR)/test4b.o
	$(CC) -o $(BINDIR)/$@ $^ $(LFLAGS) $(LIBS)
polyspeed: $(ODIR)/polyspeed.o
	$(CC) -o $(BINDIR)/$@ $^ $(LFLAGS) $(LIBS)
test4c: $(ODIR)/test4c.o
	$(CC) -o $(BINDIR)/$@ $^ $(LFLAGS) $(LIBS)
test4c-loop: $(ODIR)/test4c-loop.o
	$(CC) -o $(BINDIR)/$@ $^ $(LFLAGS) $(LIBS)
car: $(ODIR)/car.o
	$(CC) -o $(BINDIR)/$@ $^ $(LFLAGS) $(LIBS)
test4a_gif: $(ODIR)/test4a_gif.o
	$(CC) -o $(BINDIR)/$@ $^ $(LFLAGS) $(LIBS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
