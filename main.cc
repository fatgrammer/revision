#include <SDL2/SDL.h>
#include <bits/stdc++.h>
#include "al.h"
#include "canvas.h"
#include "cleanup.h"
#include "wrapper.h"
#include "parser.h"
using namespace std;

void test(void);
void parseInstance();
const int width = 255;
const int height = 255;
int main(void) {
    test();
  parseInstance();
}
void test() {
  Renderer ren(width, height);
}

void parseInstance() {
  vector<string> ctn{"123", "+", "126", "*", "124", "-", "125", "/", "12"};
  vector<int> vi;
  //   for (int i = 10; i > 0; --i){
  //       vi.push_back(i);
  //   }
  unique_ptr<Node<string>> root = std::make_unique<Node<string>>();
  //   root->op_ = "root";
  //   cout << root->op_ << endl;

  std::for_each(ctn.begin(), ctn.end(), [&root](string& e) {
    //   root->addNode(e);
    parse(root, e);
  });
  //   for (int i = 0; i < ctn.size(); ++i) {
  //     parse(root, ctn[i]);
  //   }
  // cout << root->right->op_ << endl;
  //   root->addNode("asd");
  //   root->build(ctn);

  root->traverse();
  cout << endl;
  root->postTraverse();
  cout << endl;
}