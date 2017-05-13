CXX = $(shell root-config --cxx)
LD = $(shell root-config --ld)
INC = $(shell pwd)
Repo = $(shell git rev-parse --show-toplevel)
SRC = $(Repo)/src

CPPFLAGS := $(shell root-config --cflags) -I$(INC)/include 
LDFLAGS := $(shell root-config --glibs) 
CPPFLAGS += -g -std=c++14

TARGET = dat2root
SRC = dat2root.cc src/Aux.cc src/Config.cc

TARGET2 = datroot2root
SRC2 = datroot2root.cc src/Aux.cc src/Config.cc

<<<<<<< HEAD
TARGET3 = dat2root_plus_pixel
SRC3 = dat2root_plus_tracker.cc src/Aux.cc src/Config.cc

OBJ = $(SRC:.cc=.o)
#OBJ2 = $(SRC2:.cc=.o)
#OBJ3 = $(SRC3:.cc=.o)
=======
TARGET3 = dat2rootPixels
SRC3 = dat2rootPixels.cc src/Aux.cc src/Config.cc

TARGET4 = SkimTree
SRC4 = SkimTree.cc

OBJ = $(SRC:.cc=.o)
OBJ2 = $(SRC2:.cc=.o)
OBJ3 = $(SRC3:.cc=.o)
OBJ4 = $(SRC4:.cc=.o)
>>>>>>> 1e90816b046677fcdeaf371f4133fedfa0950b9a

all : $(TARGET) $(TARGET2) $(TARGET3) $(TARGET4)

$(TARGET) : $(OBJ)
	@echo $@
	$(LD) $(CPPFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

#$(TARGET2) : $(OBJ2)
#	@echo $@
#	$(LD) $(CPPFLAGS) -o $(TARGET2) $(OBJ2) $(LDFLAGS)

<<<<<<< HEAD
#$(TARGET3) : $(OBJ3)
#	@echo $@
#	$(LD) $(CPPFLAGS) -o $(TARGET3) $(OBJ3) $(LDFLAGS)
=======
$(TARGET3) : $(OBJ3)
	@echo $@
	$(LD) $(CPPFLAGS) -o $(TARGET3) $(OBJ3) $(LDFLAGS)

$(TARGET4) : $(OBJ4)
	@echo $@
	$(LD) $(CPPFLAGS) -o $(TARGET4) $(OBJ4) $(LDFLAGS)

>>>>>>> 1e90816b046677fcdeaf371f4133fedfa0950b9a

%.o : %.cc
	@echo $@
	$(CXX) $(CPPFLAGS) -o $@ -c $<
clean :
	rm -f *.o src/*.o $(Aux)/src/*.o $(TARGET) $(TARGET2) $(TARGET3) *~
