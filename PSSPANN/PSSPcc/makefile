# list dependencies between source code files
CPP = g++
OFLAG = -o
CPPFLAGS = -I/usr/include -I/usr/include/boost -std=c++11
CFLAGS=-std=c99
CXXFLAGS=-Weffc++
objects = main.o try.o PSSPANNdata.o ANNCore.o
prefix=/usr/local
PROGRAM = PSSPcc
.SUFFIXES: .cpp .o .c .h
#.cpp.exe:
#	$(CPP) $<
.cpp.o:
	$(CPP) $(CPPFLAGS) -c $<
.c.o:
	$(CPP) $(CFLAGS) -c $<

$(PROGRAM): $(objects)
	$(CPP) $(OFLAG) $(PROGRAM) -L/usr/lib $(objects) -lboost_program_options
	chmod 755 $(PROGRAM)
try.o: try.cpp try.h Amino_Acid_Map.h
PSSPANNdata.o: PSSPANNdata.cpp Amino_Acid_Map.h PSSPANNdata.h
ANNCore.o: ANNCore.cpp ANNCore.h
main.o: main.cpp PSSPANNdata.h try.h ANNCore.h

.PHONY : clean install uninstall
install:
	install -C -m 755 $(PROGRAM) $(prefix)/bin
uninstall:
	rm $(prefix)/bin/$(PROGRAM)
clean:
	rm $(PROGRAM) $(objects)
