
CXXFLAGS=-c -I./src/include
LDFLAGS=
CXX=c++
LD=c++
SRC:=$(shell find ./src -type f -name "*.cpp")
OBJ:=$(SRC:.cpp=.o)

all: disasm sample

clean:
	@rm -f $(OBJ) helper/sample.o sample

%.o: %.cpp
	@echo "\x1B[0;1;32m [  CXX  ]\x1B[0m $<"
	@$(CXX) $(CXXFLAGS) -o $@ $<

disasm: $(OBJ)
	@echo "\x1B[0;1;34m [  LD   ]\x1B[0m disasm"
	@$(LD) $(LDFLAGS) $(OBJ) -o disasm

sample:
	@echo "\x1B[0;1;32m [  CXX  ]\x1B[0m helper/sample.cpp"
	@$(CXX) $(CXXFLAGS) -o helper/sample.o helper/sample.cpp
	@echo "\x1B[0;1;34m [  LD   ]\x1B[0m sample"
	@$(LD) $(LDFLAGS) helper/sample.o -o sample
