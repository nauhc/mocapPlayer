# Motion capture viewer Makefile 
# Jernej Barbic, Yili Zhao, USC

include Makefile.FLTK

FLTK_PATH=../fltk-1.3.0
PLAYER_OBJECT_FILES = displaySkeleton.o interface.o motion.o posture.o skeleton.o transform.o vector.o mocapPlayer.o ppm.o pic.o performanceCounter.o
COMPILER = g++
COMPILEMODE= -O2
COMPILERFLAGS = $(COMPILEMODE) -I$(FLTK_PATH) $(CXXFLAGS)
LINKERFLAGS = $(COMPILEMODE) $(LINKFLTK_ALL)

all: mocapPlayer

mocapPlayer: $(PLAYER_OBJECT_FILES)
	$(COMPILER) $^ $(LINKERFLAGS) -o $@

%.o: %.cpp 
	$(COMPILER) -c $(COMPILERFLAGS) $^

clean:
	-rm -rf core *.o *~ "#"*"#" test

