#include <vector>
#include <iostream>
using namespace std;

// Given a list of iterators, implement a FlattenedIterator class which
// incrementally iterates over the integers from all the iterators in an interleaved fashion.
//
// An iterator implements the next() and hasNext() interface. You're free to use them,
// and you will implement them on the FlattenedIterator class.
//
// Things to clarify:
//
// - You're free to initialize FlattenedIterator with any data structure of your choice for the iterators.
//
// Test Cases
//
// For iterator set [1,2,3], [4,5] and [6,7,8], the FlattenedIterator should
// yield an iterator over [1,4,6,2,5,7,3,8].
//
// Iterators [1,2,3], [] and [6,7], yield iterator [1,6,2,7,3].
//

class Iterator {
private:
  int idx;
  vector<int> v_;

public:
  Iterator() {
    idx = 0;
  }
  void SetV(vector<int>& v) {
    v_ = v;
    idx = 0;
  }
  int Next() {
    if (idx < v_.size()) return v_[idx++];
    throw "There's no more elements to be iterated";
  }
  bool HasNext() {
    if(idx < v_.size()) return true;
    return false;
  }
};

class FlattenedIterator : public Iterator {
public:
void SetV(vector<Iterator*>& itr_list) {
    vector<int> v;
    bool itr_has_elements;
    do {
      itr_has_elements = false;
      for(int i = 0; i < itr_list.size(); i++) {
        if(itr_list[i]->HasNext()) {
          itr_has_elements = true;
          v.push_back(itr_list[i]->Next());
        }
      }
    } while(itr_has_elements);
    Iterator::SetV(v);
  }
};


int main() {
  Iterator itr1, itr2, itr3;
  vector<int> v;
  v.push_back(1); v.push_back(2); v.push_back(3);
  itr1.SetV(v);
  v.clear();
  v.push_back(4); v.push_back(5);
  itr2.SetV(v);
  v.clear();
  v.push_back(6); v.push_back(7); v.push_back(8);
  itr3.SetV(v);
  vector<Iterator*> itrs;
  itrs.push_back(&itr1); itrs.push_back(&itr2); itrs.push_back(&itr3);
  FlattenedIterator flat_itr;
  flat_itr.SetV(itrs);
  while(flat_itr.HasNext())
    cout << flat_itr.Next() << endl;
  v.clear();
  v.push_back(1); v.push_back(2); v.push_back(3);
  itr1.SetV(v);
  v.clear();
  itr2.SetV(v);
  v.clear();
  v.push_back(6); v.push_back(7);
  itr3.SetV(v);
  flat_itr.SetV(itrs);
  while(flat_itr.HasNext())
    cout << flat_itr.Next() << endl;
  return 0;
}
