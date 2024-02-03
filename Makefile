
CXXFLAGS=-c -I./src/include
LDFLAGS=
CXX=c++
LD=c++
SRC:=$(shell find ./src -type f -name "*.cpp")
OBJ:=$(SRC:.cpp=.o)

all: disasm

clean:
	@rm -f $(OBJ)

%.o: %.cpp
	@echo "\x1B[0;1;32m [  CXX  ]\x1B[0m $@"
	@$(CXX) $(CXXFLAGS) -o $@ $<

disasm: $(OBJ)
	@echo "\x1B[0;1;34m [  LD   ]\x1B[0m disasm"
	@$(LD) $(LDFLAGS) $(OBJ) -o disasm
