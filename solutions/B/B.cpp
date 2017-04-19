#include <fstream>

using namespace std;

int main() {
  ifstrema fin ("B.in");
  ofstream fout ("B.out");
  
  int n, x, y;
  char ch, temp;
  fin >> n >> x >> y;
  for (int i = 0; i < n; i++) {
    cin >> ch >> temp;
    if (ch == 'N')
      y += temp;
    else if (ch == 'W')
      x += temp;
    else if (ch == 'S')
      y -= temp;
    else
      x -= temp;
  }
  
  fout << x << y << endl;
  fout.close();
  
  return 0;
}
