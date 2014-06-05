$ g++ -std=c++11 main.cpp; ./a.exe
Length of vector1: 0
Length of vector2:
>>> 3
Length of vector2: 3
Add size of vector2
>>> 1
Length of vector2: 4
Input 4 elements in v2   # v2 = {1, 2, 3, 4}
1 2 3 4
Length of vector3: 4
Input index of v3
>>> 1
2
Input index of v3
>>> 2
3                        # v3[2] == 3 == v2[2]
Input index of v3      
>>> 5
IndexOutofBounds         # exception
Input index of v3
>>> -10
IndexOutofBounds         # exception
Input index of v3