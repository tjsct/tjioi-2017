#include <fstream>

using namespace std;

int main() {
  ifstream fin ("A.in");
  ofstream fout ("A.out")
  
  int n, t;
  fin >> n >> t;
  for (int i = 0; i < n; i++) {
    int a, b;
    fin >> a >> b;
    if (a / 100.0 * t < b * 1.0)
      fout << "Once you quit track you can never come back" << endl;
    else
      fout << "What do you mean I'm slow" << endl;
  }
  fout.close();
  
  return 0;
}
