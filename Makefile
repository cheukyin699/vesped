CXX := g++
CXXFLAGS := -c
LD := g++
LDFLAGS :=

EXE := vesped
OBJ := obj/vesped.o obj/editor.o obj/parser.o


all: $(EXE)

clean:
	@echo "Removing $(EXE) and object files"
	rm -f $(EXE)
	rm -f $(OBJ)

$(EXE): obj/ $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o $@

obj/:
	@echo "Creating directory: $@"
	mkdir $@

obj/vesped.o: src/vesped.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

obj/editor.o: src/editor.cpp src/editor.h
	$(CXX) $(CXXFLAGS) $< -o $@

obj/parser.o: src/parser.cpp src/parser.h
	$(CXX) $(CXXFLAGS) $< -o $@

