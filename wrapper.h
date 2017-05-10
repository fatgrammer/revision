#ifndef WRAPPER_H
#define WRAPPER_H

struct Renderer {
  Renderer(int x = 400, int y = 400) : width(x), height(y) {
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
  void renderPresent() { SDL_RenderPresent(renderer); }
  void drawAllPoints() {
    for (int i = 0; i < width; ++i) {
      for (int j = 0; j < height; ++j) {
        this->setRenderDrawColor(i, j, (i + j) / 2, 255);
        this->drawPoint(i, j);
      }
    }
  }

 private:
  int width;
  int height;
  SDL_Window* window;
  SDL_Renderer* renderer;
};

#endif