#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include "al.h"
#include "canvas.h"
#include "cleanup.h"
using namespace std;
void test(void);

int main(void) {
  test();
}

struct Renderer {
  Renderer(int x = 400, int y = 400) {
    SDL_CreateWindowAndRenderer(x, y, 0, &window, &renderer);
  }
  ~Renderer() { cleanup(renderer, window); }
  void drawPoint(int x, int y) {
    SDL_RenderDrawPoint(renderer, x, y);  // Renders on middle of screen.
  }
  void setRenderDrawColor(int r, int g, int b, int a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
  }
  void clearRender() { SDL_RenderClear(renderer); }
  void render() { SDL_RenderPresent(renderer); }

 private:
  SDL_Window* window;
  SDL_Renderer* renderer;
};
void test() {
  Renderer ren(100, 100);
  ren.setRenderDrawColor(255, 0, 0, 255);
  ren.clearRender();
  for (int i = 0; i < 400; ++i) {
    ren.drawPoint(i, i);  // Renders on middle of screen.
  }
  ren.render();
  getchar();
}
