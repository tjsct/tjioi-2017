#include <iostream>

using namespace std;

int main() { 
  int n, t;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a / 100.0 * t < b * 1.0)
      cout << "Once you quit track you can never come back" << endl;
    else
      cout << "What do you mean I'm slow" << endl;
  }
  
  return 0;
}
