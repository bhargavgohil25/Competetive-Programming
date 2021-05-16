#include<stdio.h>

#include<stdlib.h>

int main() {
  int t, n, x, y;
  long long int i, a = 10000000000, b = -10000000000;
  char ch;

  scanf("%d", & t);
  for (x = 1; x < t + 1; x++) {
    scanf("%d", & n);
    for (y = 1; y < n + 1; y++) {
      scanf("%c%lld", & ch, & i);
      if ((ch == 'L') && (i < a)) {
        a = i;
      } else if ((ch == 'R') && (i > b)) {
        b = i;
      }
    }
    if (a - b > 0) {
      printf("\n %d", a - b - 1);
    } else {
      printf("\n -1");
    }
  }
}