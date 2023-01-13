CC=g++

all : main

clean :
	rm *.o

distclean : clean
	rm main.exe

rebuild : clean all

main : *.o
	$(CC) -o main.exe *.o

*.o : $(PATH_SRC)*.cpp
	$(CC) -c $^
