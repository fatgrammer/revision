#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include "al.h"
#include "canvas.h"
#include "cleanup.h"
#include "wrapper.h"
#include <unistd.h>
using namespace std;

void test(void);
const int width = 255;
const int height = 255;
int main(void) {
  test();
}
void test() {
  Renderer ren(width, height);
  ren.setRenderDrawColor(0, 0, 0, 255);
  ren.clearRender();
  // for (int i = 0; i < width; ++i) {
  //   for (int j = 0; j < height; ++j) {
  //     ren.setRenderDrawColor(i, j, (i + j) / 2, 255);
  //     ren.drawPoint(i, j);
  //   }
  // }
  ren.drawAllPoints();
  ren.renderPresent();
  sleep(1);
}
