#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include "al.h"
#include "canvas.h"
using namespace std;
int main(void) {
  vector<int> vi = gener();
  print(vi);
  // Al::bubbleSort(vi);
  Al::simpleInsertionSort(vi);
  print(vi);
}
