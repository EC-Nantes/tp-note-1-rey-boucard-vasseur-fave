CC=g++

all : main

clean :
	del *.o

distclean : clean
	del main.exe

rebuild : distclean all

main : *.o
	$(CC) -o main.exe *.o

*.o : $(PATH_SRC)*.cpp
	$(CC) -c $^
