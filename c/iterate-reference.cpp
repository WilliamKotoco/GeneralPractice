#include <iostream>
#include <vector>
int main (int argc, char *argv[]) {
  using namespace std;
  vector<int> vec {1,2,3,4};

  for (auto &val : vec)
  {
    cout <<val <<" ";
    val = 1;
  }
  cout << "\n"; 


  for (auto &val : vec)
    cout << val <<" ";
  cout <<"\n";



  /// Take copy. Change does not affect but it takes 
  /// a lot of memorry
      for (auto val : vec)
        cout << val << " ";
  return 0;
}
