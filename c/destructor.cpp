#include <iostream>
struct Test{
  int *array = nullptr;

  Test(){
    array = new int[5] {1,2,3,4,5};
  }

  ~Test(){
    std::cout<<"Called destructor" <<"\n";
    delete[] array;
    array = nullptr;
  }

  void print(){
    std::cout <<array[0] << array[1] << array[4];
  }


};

int main (int argc, char *argv[]) {
  Test e;
  e.print();
  return 0;
}
