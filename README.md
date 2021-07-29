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

Under the `build` folder :
* `bin`  : all executable tools in this folder
* `lib`  : all shared objects in this folder
* `data` : all data in this folder

## Table of Contents
* DH Table
    - [Convet DH Table (Craig) to Transform Matrix with command line arguments](#dh)
    - [Convet DH Table (Craig) to Transform Matrix with manual input](#dh2tf) 
* Rotate Matrix
    - [Convert angle to rotate with manual input](#angleconverter)

## DH
* [dh_table](data/dh_table.txt)

### Usage
`-h, --help` : Print help and exit

`-f, --file` : File path of DH table (Please use txt file to record the table)

```shell
$ ./bin/DH -f data/dh_table.txt 0 6
Transform Matrix 6->0 : 
  0.957  -0.199   0.209 699.877
 -0.283  -0.791   0.542 322.117
  0.057  -0.578  -0.814 276.399
  0.000   0.000   0.000   1.000
```

## DH2TF
Input the number of joints to build DH table, then input A and B (B frame relate to A frame) to show the Transform Matrix

## AngleConverter
Input the angles and rotate method(euler or fixed) to show the rotate matrix
