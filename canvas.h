#ifndef _Canvas_H_
#define _Canvas_H_
#include <fstream>
#include <vector>
struct Canvas {
  void render() {
    fs << "P3\n"
       << width << " " << height << "\n"
       << " 256\n";
    for (int x = 0; x < width; ++x) {
      for (int y = 0; y < height; ++y) {
        for (int i = 0; i < 3; ++i) {
          fs << texture[x * width + y] << " ";
        }
      }
    }
  }
  void setPixel(int x, int y, int depth) { texture[x * width + y] = depth; }
  Canvas(int width, int height)
      : width(width), height(height), texture(width * height) {
    fs.open("g.ppm",
            std::fstream::in | std::fstream::out | std::fstream::trunc);
  }
  ~Canvas() { fs.close(); }
  int width;
  int height;
  std::vector<int> texture;
  // std::vector<Color> pallete;
  std::fstream fs;
};

#endif