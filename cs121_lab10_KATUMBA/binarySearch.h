#ifndef _BINARYSEARCH_H
#define _BINARYSEARCH_H
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string getFileName();
void openFile(string nameOf, fstream& inOut);
void BubbleSort(int array[], const int SIZE);
int BinarySearch(int array[], const int SIZE, int key);
#endif