# list dependencies between source code files
CXX = $(shell wx-config --cxx)
OFLAG = -o
CPPFLAGS = -I/usr/include -std=c++11
CFLAGS=-std=c99
objects = MainFrame.o PSSP_protoApp.o TestDialog.o PredictionDialog.o PSSP_protoMain.o TrainingDialog.o
prefix=/usr/local
PROGRAM = PSSP-proto
.SUFFIXES: .cpp .o .c .h
#.cpp.exe:
#	$(CPP) $<
.cpp.o:
	$(CXX) $(CPPFLAGS) -c `wx-config --cxxflags` $<
.c.o:
	$(CXX) $(CFLAGS) -c `wx-config --cxxflags` $<

$(PROGRAM): $(objects)
	$(CXX) $(OFLAG) $(PROGRAM) $(objects) `wx-config --libs`
	chmod 755 $(PROGRAM)


MainFrame.o:MainFrame.cpp MainFrame.h PredictionDialog.h TrainingDialog.h TestDialog.h
PredictionDialog.o:PredictionDialog.cpp PredictionDialog.h
PSSP_protoApp.o:PSSP_protoApp.cpp PSSP_protoApp.h
PSSP_protoMain.o:PSSP_protoMain.cpp PSSP_protoMain.h MainFrame.h
TestDialog.o:TestDialog.cpp TestDialog.h
TrainingDialog.o:TrainingDialog.cpp TrainingDialog.h



.PHONY : clean install uninstall
install:
	install -C -m 755 $(PROGRAM) $(prefix)/bin
uninstall:
	rm $(prefix)/bin/$(PROGRAM)
clean:
	rm $(PROGRAM) $(objects)
