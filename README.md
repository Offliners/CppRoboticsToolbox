# Cpp Robotics Toolbox
Using `C++ 11` to implement some simple robotics tools

## Requirment
* CMake
* Eigen

## Build
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Under the `build` folder :
* `bin`  : all executable tools in this folder
* `lib`  : all shared objects in this folder
* `data` : all data in this folder

## Table of Contents
* DH Table
    - [Convet DH Table (Craig) to Transform Matrix with manual input](#dh2tf) 
    - [Convet DH Table (Craig) to Transform Matrix with command line arguments](#dh)
    
* Rotate Matrix
    - [Convert angle to rotate with manual input](#angleconverter)
    - [Convert angle to rotate with command line arguments](#ac)

## DH2TF
Input the number of joints to build DH table, then input A and B (B frame relate to A frame) to show the Transform Matrix
```
$ ./bin/DH2TF
Input amount of joint : 6
Input DH Table (Craig)
=================================================
Index    alpha(i-1)    a(i-1)    d(i)    theta(i)
   1 | 0 0 0 15
   2 | -90 0 220 -40
   3 | 0 430 -90 -50
   4 | -90 0 430 30
   5 | 90 0 0 70
   6 | -90 0 0 25
====== Menu ======
1. Show DH Table
2. Find TF Matrix
3. Quit
==================
Input your select : 
1
=================================================
Index    alpha(i-1)    a(i-1)    d(i)    theta(i)
   1 |            0         0       0          15
   2 |          -90         0     220         -40
   3 |            0       430     -90         -50
   4 |          -90         0     430          30
   5 |           90         0       0          70
   6 |          -90         0       0          25
====== Menu ======
1. Show DH Table
2. Find TF Matrix
3. Quit
==================
Input your select : 
2
B relate to A
Input A : 0
Input B : 6
Transform Matrix 6->0 : 
  0.957  -0.199   0.209 699.877
 -0.283  -0.791   0.542 322.117
  0.057  -0.578  -0.814 276.399
  0.000   0.000   0.000   1.000

====== Menu ======
1. Show DH Table
2. Find TF Matrix
3. Quit
==================
Input your select : 
3
```

## DH
* [dh_table](data/dh_table.txt)

`-h, --help` : Print help and exit

`-f, --file` : File path of DH table (Please use txt file to record the table)

##### Usage
```
$ ./bin/DH -h
"DH" command arguments usage :
[-h | --help] --> Print help and exit
[-f | --file] --> File path of DH table (Please use txt file to record the table)

$ ./bin/DH -f data/dh_table.txt 0 6
Transform Matrix 6->0 : 
  0.957  -0.199   0.209 699.877
 -0.283  -0.791   0.542 322.117
  0.057  -0.578  -0.814 276.399
  0.000   0.000   0.000   1.000
```

## AngleConverter
Input the angles and rotate method(euler or fixed) to show the rotate matrix
```
$ ./bin/AngleConverter
======= Menu =======
1. Show angle format
2. Input angles & Show Rotate Matrix
3. Quit
==================
Input your select : 
1
If rotation method is "fixed", the input sequence of angles is "gamma->beta->alpha"
If rotation method is "euler", the input sequence of angles is "alpha->beta->gamma"
======= Menu =======
1. Show angle format
2. Input angles & Show Rotate Matrix
3. Quit
==================
Input your select : 
2
Input angles in order (split by space) : 60 30 0
Input method (fixed or euler) : fixed
Input axis sequence (ex: xyz) : xyz
 0.866  0.433  0.250
 0.000  0.500 -0.866
-0.500  0.750  0.433
======= Menu =======
1. Show angle format
2. Input angles & Show Rotate Matrix
3. Quit
==================
Input your select : 
3
```

## AC
`-h, --help` : Print help and exit

`-m, --method` : Input rotate method(euler or fixed, case insensitive)

`-s, --sequence` : The sequence of input angles(case insensitive)

##### Usage
```
$ ./bin/AC -h
"AC" command arguments usage :
[-h | --help] --> Print help and exit
[-m | --method] --> Input rotate method(euler or fixed, case insensitive)
[-s | --sequence] --> The sequence of input angles(case insensitive)
                      If rotation method is "fixed", the input sequence of angles is "gamma->beta->alpha"
                      If rotation method is "euler", the input sequence of angles is "alpha->beta->gamma"

$ ./bin/AC -m euler -s zyx 0 30 60
 0.866  0.433  0.250
 0.000  0.500 -0.866
-0.500  0.750  0.433

$ ./bin/AC -m fixed -s xyz 60 30 0
 0.866  0.433  0.250
 0.000  0.500 -0.866
-0.500  0.750  0.433
```