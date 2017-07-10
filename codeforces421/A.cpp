#include <iostream>
#include <cmath>

int main()
{
  int n, a;
  cin >> n >> a;
  double a_max = 180 * (n - 2) / n;
  double a_min = (180 - a_max) / 2;
  int i = 3;
  int i_small = 3;
  double a_small = 180;
  for (double a_cur = a_max; a_cur >= a_min; a_cur -= a_min) {
    double a_curdiff = fabs(((double) a) - a_cur);
    if (a_curdiff < a_small) {
      i_small = i;
      a_small = a_curdiff;
    }
    i++;
  }
  cout << "1 2 " << i_small << endl;
  return 0;
}