# Dan Teplitski
# 312895147

a.out: Cell.o Board.o Game.o HumanPlayer.o StdLogic.o main.o ConsoleDisplay.o
	g++ Cell.o Board.o Game.o HumanPlayer.o StdLogic.o main.o ConsoleDisplay.o

main.o: main.cpp Game.h Globals.h
	g++ -c main.cpp

Cell.o: Cell.cpp Cell.h Globals.h
	g++ -c Cell.cpp Cell.h

Board.o: Board.cpp Board.h Globals.h Cell.h Globals.h
	g++ -c Board.cpp Board.h

Game.o: Game.cpp Game.h Board.h Player.h StdLogic.h HumanPlayer.h Globals.h ConsoleDisplay.h Display.h
	g++ -c Game.cpp Game.h

HumanPlayer.o: HumanPlayer.cpp HumanPlayer.h Player.h Globals.h
	g++ -c HumanPlayer.cpp HumanPlayer.h

StdLogic.o: StdLogic.cpp StdLogic.h Logic.h Player.h Globals.h
	g++ -c StdLogic.cpp StdLogic.h

ConsoleDisplay.o: ConsoleDisplay.cpp ConsoleDisplay.h Display.h
	g++ -c ConsoleDisplay.cpp ConsoleDisplay.h
