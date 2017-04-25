<<<<<<< HEAD
=======

>>>>>>> 6c6a422c641503051b31deb840240863814f9507
#include <bits/stdc++.h>
#include "al.h"
#include "canvas.h"
using namespace std;
<<<<<<< HEAD
template <typename T>
void outp(const T& v) {
  for (const auto& i : v) {
    cout << i << " ";
  }
  cout << endl;
}
struct Node {
  Node(int size, int sum = 0)
      : _size(size), _nextAvailNode(size), _nextNodeAddress(size) {}
  int sum;
  int _size;
  vector<int> _nextAvailNode;
  vector<shared_ptr<Node>> _nextNodeAddress;
};

void addTree(Node& root, int presum, int max) {
  cout << presum << endl;
  for (int i = 1; i <= max; ++i) {
    cout << i << " i " << endl;
    if (presum + i <= root._size) {
      root._nextNodeAddress[i] = make_shared<Node>(root._size);
      root._nextAvailNode[i] = 1;

      addTree(*root._nextNodeAddress[i], presum + i, max - i);
    } else {
      break;
    }
  }

  cout << "s:" << presum << endl;
}
void traverse(Node& root) {
  for (auto& i : root._nextAvailNode) {
    cout << i << " ";
  }
  cout << endl;
}
int main(void) {
  // vector<int> vi;
  // for (int i = 0; i < 20; ++i) {
  //   vi.push_back(i);
  // }

  // std::random_device rd;
  // std::mt19937 g(rd());

  // std::shuffle(vi.begin(), vi.end(), g);
  // outp(vi);
  // // Al::bubbleSort(vi);
  // Al::simpleInsertionSort(vi);
  // outp(vi);
  int n = 2;
  Node root(n);
  addTree(root, 0, n);
  // traverse(root);
=======
int main(void) {
  vector<int> vi = gener(20);
  print(vi);
  // rotate(vi.begin(), vi.begin() + 1, vi.end());
  // Al::bubbleSort(vi);
  // Al::simpleInsertionSort(vi);
  // Al::selectionSort(vi);
  Al::slowSort(vi);
  print(vi);
>>>>>>> 6c6a422c641503051b31deb840240863814f9507
}
