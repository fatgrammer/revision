#ifndef Parser_H
#define Parser_H
#include <string>
#include <memory>
#include <iostream>
#include <algorithm>
template <typename T>
struct Node {
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

  Node() = default;

  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;
  T op_;
};
template <typename T>
void parse(std::unique_ptr<Node<T>>& root, T val) {
  if (root->left == nullptr) {
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
#endif