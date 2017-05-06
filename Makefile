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
SRC = datroot2root.cc src/Aux.cc src/Config.cc

OBJ = $(SRC:.cc=.o)

all : $(TARGET) $(TARGET2)

$(TARGET) : $(OBJ)
	@echo $@
	$(LD) $(CPPFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

$(TARGET2) : $(OBJ)
	@echo $@
	$(LD) $(CPPFLAGS) -o $(TARGET2) $(OBJ) $(LDFLAGS)


%.o : %.cc
	@echo $@
	$(CXX) $(CPPFLAGS) -o $@ -c $<
clean :
	rm -f *.o src/*.o $(Aux)/src/*.o $(TARGET) $(TARGET2) *~
