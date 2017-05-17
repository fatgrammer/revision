#include <SDL2/SDL.h>
#include <bits/stdc++.h>
#include "al.h"
#include "canvas.h"
#include "cleanup.h"
#include "wrapper.h"
using namespace std;

void test(void);
const int width = 255;
const int height = 255;
int main(void) { test(); }
void test() { Renderer ren(width, height); }
