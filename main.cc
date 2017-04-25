#include <bits/stdc++.h>
#include "al.h"
#include "canvas.h"
using namespace std;
template <typenaintint main(void) {
  vector<int> vi = gener(20);
  print(vi);
  // rotate(vi.begin(), vi.begin() + 1, vi.end());
  // Al::bubbleSort(vi);
  // Al::simpleInsertionSort(vi);
  // Al::selectionSort(vi);
  Al::slowSort(vi);
  print(vi);
}
