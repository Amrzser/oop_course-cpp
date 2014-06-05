1. $ g++ -std=c++11 main.cpp
2. $ ./a.out                         # the map file is castle.txt   

$ ./a.exe                            # because I'm on windows now
The castle came, game start.

This is a lobbry room
And called 19Room
west
>>> west

This is a normal room
And called 18Room
west  east
>>> west

This is a normal room
And called 17Room
north  south  west  east
>>> north

This is a normal room
And called 7Room
south  west
>>> west

This is a princess room             #come to princess, you should be happy
And called 6Room
south  west  east
You get the princess. Come back
>>> south

This is a monster room              #come to monster, game over
And called 16Room
north  south  west  east
You die. Game over!
The castle disappered.

-------------------------------------------------------------

$ ./a.exe
The castle came, game start.

This is a lobbry room
And called 19Room
west
>>> west

This is a normal room
And called 18Room
west  east
>>> west

This is a normal room
And called 17Room
north  south  west  east
>>> north

This is a normal room
And called 7Room
south  west
>>> west

This is a princess room             #get the princess
And called 6Room
south  west  east
You get the princess. Come back
>>> east

This is a normal room
And called 7Room
south  west
>>> south

This is a normal room
And called 17Room
north  south  west  east
>>> east

This is a normal room
And called 18Room
west  east
>>> east

This is a lobbry room
And called 19Room
west
You win!                            #win
The castle disappered.

3. This game is fun, let's play more, and make the map stronger

4. Classes don't have *.cpp file, because I must program faster,
   too much work to do, some part of programs are hard to read,
   I'm sorry!

                                                Amrzs 2014/05/11