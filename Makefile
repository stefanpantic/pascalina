CXX 		= clang++
STANDARD 	= c++17
DEBUG 		= -ggdb -O0
CXXFLAGS 	= -I./include $(shell llvm-config --cxxflags) -Wno-unknown-warning-option -Wno-unused-command-line-argument -std=$(STANDARD) -Wall -Wextra $(DEBUG)
LDFLAGS 	= $(shell llvm-config --ldflags --libs --system-libs)
SRC 		= $(wildcard src/*.cpp)
HEAD 		= $(SRC:src=include)
HEAD 		= $(HEAD:.cpp=.hpp)
HEADONLY 	= $(wildcard include/*.hpp include/ast/*.hpp include/types/*.hpp)
OBJ 		= $(patsubst src/%.cpp, $(BUILD)/%.o, $(SRC))
BUILD 		= build
TITLE 		= pascalina.out
TARGET 		= $(BUILD)/$(TITLE)

.PHONY: clean zip

all: $(BUILD) $(TARGET)

$(TARGET): $(BUILD)/parser.o $(BUILD)/lexer.o $(BUILD)/main.o $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILD)/%.o: src/%.cpp include/%.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD)/main.o: main.cpp parser.hpp $(HEADONLY)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD)/parser.o: parser.cpp $(HEADONLY)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD)/lexer.o: lexer.cpp parser.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

parser.cpp: parser.ypp
	yacc -d -v -o $@ $< -t

lexer.cpp: lexer.lex
	flex -o $@ $<

$(BUILD):
	@test ! -d $(BUILD) && mkdir $(BUILD)

clean:
	rm -rf build
	rm -f parser.hpp parser.cpp lexer.cpp parser.output

zip:
	zip -r $(TITLE:.out=.zip) ./
