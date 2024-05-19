CC = g++
CFLAGS = -Wall -O3

tran: testtran.exe
	
sig: testsig.exe
	
test1: test1.exe
	
test2: test2.exe
	
clean:
	rm -rf *.o *.exe Test*


signal.o: signal.cpp signal.hpp
	$(CC) $(CFLAGS) -c signal.cpp

transformation.o: transformation.cpp transformation.hpp signal.hpp
	$(CC) $(CFLAGS) -c transformation.cpp

signauxvaries.o: signauxvaries.cpp signauxvaries.hpp signal.hpp
	$(CC) $(CFLAGS) -c signauxvaries.cpp


testsig.exe: signal.o testsig.cpp
	$(CC) $(CFLAGS) signal.o testsig.cpp -o testsig.exe

testtran.exe: signal.o transformation.o testtran.cpp
	$(CC) $(CFLAGS) signal.o transformation.o testtran.cpp -o testtran.exe

test1.exe: signal.o transformation.o test1.cpp
	$(CC) $(CFLAGS) signal.o transformation.o test1.cpp -o test1.exe

test2.exe: signal.o transformation.o signauxvaries.o test2.cpp
	$(CC) $(CFLAGS) signal.o transformation.o signauxvaries.o test2.cpp -o test2.exe