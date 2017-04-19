#include <iostream>

using namespace std;

int main() { 
  int n, x, y;
  char ch, temp;
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++) {
    cin >> ch >> temp;
    if (ch == 'N')
      y += temp;
    else if (ch == 'E')
      x += temp;
    else if (ch == 'S')
      y -= temp;
    else
      x -= temp;
  }  
  cout << x << y << endl;
  
  return 0;
}
