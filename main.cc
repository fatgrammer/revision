#include <bits/stdc++.h>
#include "al.h"
#include "canvas.h"
using namespace std;
int main(void) {
  vector<int> vi = gener(20, false);
  print(vi);
  // rotate(vi.begin(), vi.begin() + 1, vi.end());
  // Al::bubbleSort(vi);
  // Al::simpleInsertionSort(vi);
  // Al::selectionSort(vi);
  // Al::slowSort(vi);

  //  next_permutation(vi.begin(), vi.end());
  //  print(vi);
  string rep("1122333");
  auto last = unique(rep.begin(), rep.end());
  rep.erase(last, rep.end());
  print(rep);
}
