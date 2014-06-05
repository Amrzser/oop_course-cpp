Following these steps:
1. enter these commands into your terminal
    $ g++ -std=c++11 -o pdadd pdadd.cpp diary.cpp entity.cpp date.cpp 
    $ g++ -std=c++11 -o pdlist pdlist.cpp diary.cpp entity.cpp date.cpp 
    $ g++ -std=c++11 -o pdshow pdshow.cpp diary.cpp entity.cpp date.cpp 
    $ g++ -std=c++11 -o pdremove pdremove.cpp diary.cpp entity.cpp date.cpp 

2. $ ./pdadd 20140101
diary.txt dosen't exist, a new one will be created.
>>> this is the first day of the new year
>>> enjoy it!
>>> .
...Diaries have been saved.

3. $ cat diary.txt
20140101
this is the first day of the new yearenjoy it!

4. then write other diaries ...

5. $ ./pdlist 20140102 20140205
...Old diaries have loaded.
20140102
20140103
20140104
20140105
...Diaries have been saved.

6. $ ./pdshow 20140103
./pdshow 20140103
...Old diaries have loaded.
20140103
today is rainy
bad!
...Diaries have been saved.

7. $ ./pdremove 20140103
...Old diaries have loaded.
Entity removed.
...Diaries have been saved.

p.s. return value is 0

8. $ ./pdshow 20140103
...Old diaries have loaded.
There isn't a 20140103 entity.
...Diaries have been saved.

p.s. return value is -1 (255)

9. There are other functions and you can try to play it

10. Enjoy diaries! 

amrzs
20140427

