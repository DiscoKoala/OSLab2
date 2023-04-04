
SOURCES = main.cpp FCFS.cpp RR.cpp SRTF.cpp

TARGET = myscheduler

CC = g++

CXXFLAGS = -g -std=c++11

OBJS:= ${SOURCES:.cpp=.o}

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

.cpp.o:
	$(CC) -c $(CXXFLAGS) $(INCDIR) $<

$(INCS): $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET) core