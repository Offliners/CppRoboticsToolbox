# Cpp Robotics Toolbox
Using `C++ 11` to implement some simple robotics tools

## Requirment
* CMake
* Eigen

## Build
```shell
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## Table of Contents
* [Convet DH Table (Craig) to Transform Matrix with command line arguments](#dh)
* [Convet DH Table (Craig) to Transform Matrix with manual input](#dh2tf) 
* [Convert angle to rotate matrix](#angleconverter)

## DH
* [dh_table](data/dh_table.txt)
```txt
0 0 0 15
-90 0 220 -40
0 430 -90 -50
-90 0 430 30
90 0 0 70
-90 0 0 25
```
![DH demo](https://github.com/Offliners/CppRoboticsToolbox/blob/main/demo/DH_demo.gif)

## DH2TF
![DH2TF demo](https://github.com/Offliners/CppRoboticsToolbox/blob/main/demo/DH2TF_demo.gif)

## Development Log
#### 2021/07/25 
Implement DH Table to Transform Matrix
