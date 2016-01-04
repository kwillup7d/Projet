OBJS = Case.o Humain.o HumainCartagena.o HumainQuestion.o Jeu.o Joueur.o JoueurCartagena.o JoueurQuestion.o Plateau.o Robot.o RobotCartagena.o RobotQuestion.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)


all : $(OBJS) main.cpp
	$(CC) $(LFLAGS) $(OBJS) main.cpp -o game.exe


clean :
	rm -rf *.o
