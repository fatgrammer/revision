#ifndef Parser_H
#define Parser_H
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
// template<typename T>
// Node<T>::RootStack{};
template <typename T>
struct Node {
  static std::vector<std::unique_ptr<Node<T>>*> RootStack;
  void addLeft(std::unique_ptr<Node<T>> node) { this->left = std::move(node); }
  void addRight(std::unique_ptr<Node<T>> node) {
    this->right = std::move(node);
  }
  void traverse() {
    if (this->left != nullptr) {
      this->left->traverse();
    }
    std::cout << op_ << " ";
    if (this->right != nullptr) {
      this->right->traverse();
    }
  }
  void postTraverse() {
    if (this->left != nullptr) {
      this->left->postTraverse();
    }
    if (this->right != nullptr) {
      this->right->postTraverse();
    }
    std::cout << op_ << " ";
  }
  void addNode(T val) {
    if (this->op_.empty()) {
      this->op_ = val;
    } else if (val < this->op_) {
      if (this->left == nullptr) {
        this->left = std::make_unique<Node<T>>();
      }
      this->left->addNode(val);
    } else if (val > this->op_) {
      //   std::cout << val << std::endl;
      if (this->right == nullptr) {
        this->right = std::make_unique<Node<T>>();
      }
      this->right->addNode(val);
    }
  }

  void build(std::vector<T> v) {
    std::for_each(v.begin(), v.end(), [this](T& e) { this->addNode(e); });
  }
  //   static std::vector<Node<T>> RootStack;
  static void parse(std::unique_ptr<Node<T>>& root, T val) {
    if (root->left == nullptr && val == "(") {
      std::unique_ptr<Node<T>> tRoot = std::make_unique<Node<T>>();
      root->left = std::move(tRoot);
      Node<T>::RootStack.push_back(&(root->left));
    } else if (root->right == nullptr && val == "(") {
      std::unique_ptr<Node<T>> tRoot = std::make_unique<Node<T>>();
      root->right = std::move(tRoot);
      Node<T>::RootStack.push_back(&(root->right));
    } else if (val == ")") {
      Node<T>::RootStack.pop_back();
    } else if (root->left == nullptr) {
      root->left = std::make_unique<Node<T>>();
      root->left->op_ = val;
    } else if (root->op_.empty()) {
      //   std::cout << val;
      root->op_ = val;
    } else if (root->right == nullptr) {
      root->right = std::make_unique<Node<T>>();
      root->right->op_ = val;
    } else if (val == "+" || val == "-") {
      std::unique_ptr<Node<T>> tmp = std::make_unique<Node<T>>();
      tmp->op_ = val;
      tmp->left = std::move(root);
      root = std::move(tmp);
    } else if (val == "*" || val == "/") {
      std::unique_ptr<Node<T>> tmp = std::make_unique<Node<T>>();
      tmp->op_ = val;
      tmp->left = std::move(root->right);
      root->right = std::move(tmp);
    } else {
      parse(root->right, val);
    }
  }
  Node() = default;

  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;
  T op_;
};
template <typename T>
std::vector<std::unique_ptr<Node<T>>*> Node<T>::RootStack{};
#endif