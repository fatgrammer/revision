#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include "al.h"
#include "canvas.h"
using namespace std;
template <typename T>
void outp(const T &v) {
  for (const auto &i : v) {
    cout << i << " ";
  }
  cout << endl;
}
int main(void) {
  // int width = 30;
  // int height = 30;
  // Canvas canvas(width, height);

  // cout << canvas.height << endl;
  // for (int x = 0; x < width; ++x) {
  //   for (int y = 0; y < width; ++y) {
  //     canvas.setPixel(x, y, 200);
  //   }
  // }
  // canvas.render();
  // cout << canvas.texture[90] << endl;
  // vector<int> vt{1, 2, 3, 4, 9};

  // int ac = accumulate(vt.begin(), vt.end(), 1,
  //                     [](int a, int b) { return a > b ? a : b; });

  // cout << ac << endl;
  vector<int> vi;
  for (int i = 0; i < 20; ++i) {
    vi.push_back(i);
  }

  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(vi.begin(), vi.end(), g);
  outp(vi);
  // Al::bubbleSort(vi);
  Al::simpleInsertionSort(vi);
  outp(vi);
}
