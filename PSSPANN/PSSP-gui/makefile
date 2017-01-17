# list dependencies between source code files
CXX = $(shell wx-config --cxx)
OFLAG = -o
CPPFLAGS = -I/usr/include -I/usr/include/boost -std=c++11
CFLAGS=-std=c99
objects = ANNCore.o MainFrame.o PredictionDialog.o PredictionMainFrame.o PredictNowFrame.o PSSPANNdata.o PSSP_protoApp.o PSSP_protoMain.o TestDialog.o TestMainFrame.o TestNowFrame.o TrainingDialog.o TrainingMainFrame.o TrainNowFrame.o try.o
prefix=/usr/local
PROGRAM = PSSP-gui
.SUFFIXES: .cpp .o .c .h
#.cpp.exe:
#	$(CPP) $<
.cpp.o:
	$(CXX) $(CPPFLAGS) -c `wx-config --cxxflags` $<
.c.o:
	$(CXX) $(CFLAGS) -c `wx-config --cxxflags` $<

$(PROGRAM): $(objects)
	$(CXX) $(OFLAG) $(PROGRAM) -L/usr/lib $(objects) `wx-config --libs` -lboost_program_options -lboost_thread -lboost_system
	chmod 755 $(PROGRAM)


ANNCore.o:ANNCore.cpp ANNCore.h
MainFrame.o:MainFrame.cpp MainFrame.h PredictionDialog.h TrainingDialog.h TestDialog.h TrainingMainFrame.h PredictionMainFrame.h TestMainFrame.h
PredictionDialog.o:PredictionDialog.cpp PredictionDialog.h
PredictionMainFrame.o:PredictionMainFrame.cpp PredictionMainFrame.h try.h PSSPANNdata.h ANNCore.h GUI_action.h
PredictNowFrame.o:PredictNowFrame.cpp PredictNowFrame.h
PSSPANNdata.o:PSSPANNdata.cpp PSSPANNdata.h Amino_Acid_Map.h
PSSP_protoApp.o:PSSP_protoApp.cpp PSSP_protoApp.h
PSSP_protoMain.o:PSSP_protoMain.cpp PSSP_protoMain.h MainFrame.h
TestDialog.o:TestDialog.cpp TestDialog.h
TestMainFrame.o:TestMainFrame.cpp TestMainFrame.h try.h PSSPANNdata.h ANNCore.h GUI_action.h
TestNowFrame.o:TestNowFrame.cpp TestNowFrame.h
TrainingDialog.o:TrainingDialog.cpp TrainingDialog.h
TrainingMainFrame.o:TrainingMainFrame.cpp TrainingMainFrame.h try.h PSSPANNdata.h ANNCore.h GUI_action.h
TrainNowFrame.o: TrainNowFrame.cpp TrainNowFrame.h
try.o:try.cpp try.h Amino_Acid_Map.h


.PHONY : clean install uninstall
install:
	install -C -m 755 $(PROGRAM) $(prefix)/bin
uninstall:
	rm $(prefix)/bin/$(PROGRAM)
clean:
	rm $(PROGRAM) $(objects)
