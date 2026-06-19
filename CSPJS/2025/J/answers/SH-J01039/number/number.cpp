#include <iostream>
using namespace std;

int cnt[15];

int main() {
  freopen("number3.in", "r", stdin);
  freopen("number.out", "w", stdout);

  for (char c = getchar(); min('0', 'a') <= c && c <= max('z', '9'); c = getchar())
    if (isdigit(c))
      cnt[ c - '0' ]++;

  for (int i = 9; i >= 0; i--)
    while (cnt[i] > 0) {
      putchar(i + '0');
      cnt[i]--;
    }

  return 0;
}
