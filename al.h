#ifndef _AL_H_
#define _AL_H_
template <typename T>
void print(const T &v) {
  using namespace std;
  for (const auto &i : v) {
    cout << i << " ";
  }
  cout << endl;
}

std::vector<int> gener(size_t size) {
  std::vector<int> vi;
  for (int i = 0; i < size; ++i) {
    vi.push_back(i);
  }

  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(vi.begin(), vi.end(), g);
  return vi;
}
#endif
struct Al {
  template <typename T>
  static void bubbleSort(std::vector<T> &v) {
    for (size_t i = 0; i < v.size() - 1; ++i) {
      for (size_t j = 1; j < v.size() - i; ++j) {
        if (v[j] < v[j - 1]) {
          std::swap(v[j], v[j - 1]);
        }
      }
    }
  }

  template <typename T>
  static void simpleInsertionSort(std::vector<T> &v) {
    for (size_t i = 1; i < v.size(); ++i) {
      T tmp = v[i];
      size_t j;
      for (j = i; j > 0 && v[j - 1] > tmp; --j) {
        v[j] = v[j - 1];
      }
      v[j] = tmp;
    }
  }

  template <typename T>
  static void selectionSort(std::vector<T> &v) {
    for (size_t i = 0; i < v.size() - 1; ++i) {
      // T min = v[i];
      size_t minIndex = i;
      for (size_t j = i + 1; j < v.size(); ++j) {
        if (v[j] < v[minIndex]) {
          minIndex = j;
        }
      }
      if (i != minIndex) {
        std::swap(v[i], v[minIndex]);
      }
    }
  }
  template <typename T>
  static void slowSort(std::vector<T> &v) {
    slowSortImpl(v.begin(), v.end() - 1);
  }

  template <typename Iter>
  static void slowSortImpl(Iter first, Iter last) {
    if (first >= last) {
      return;
    }
    Iter mid = first + (last - first) / 2;
    slowSortImpl(first, mid);
    slowSortImpl(mid + 1, last);
    if (*mid > *last) {
      std::iter_swap(mid, last);
    }
    slowSortImpl(first, last - 1);
  }
};
