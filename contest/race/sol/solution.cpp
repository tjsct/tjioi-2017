#include <iostream>

using namespace std;

int main() { 
  int n, t;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a / 100 * t <= b)
      cout << "POTATO" << endl;
    else
      cout << "SPEEDRACER" << endl;
  }
  
  return 0;
}
