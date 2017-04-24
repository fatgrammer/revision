
#include <bits/stdc++.h>
#include "al.h"
#include "canvas.h"
using namespace std;
int main(void) {
  vector<int> vi = gener(20);
  print(vi);
  // Al::bubbleSort(vi);
  // Al::simpleInsertionSort(vi);
  Al::selectionSort(vi);
  print(vi);
}
