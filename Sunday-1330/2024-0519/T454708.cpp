#include <bits/stdc++.h>

using namespace std;

typedef __int128 LL;

LL read() {
    char ch = getchar();
    LL res = 0, f = 1;
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) res = res*10 + (ch-'0'), ch = getchar();
    return res*f;
}

void print(LL x) {
    if (x < 0) { putchar('-'); x = -x; }
    if (x > 9) print(x/10);
    putchar(x%10 + '0');
}

int main()
{
    LL a, b, c;
    a = read(), b = read(), c = read();
    print(a*b + c);
  return 0;
}
