#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 1e5 + 5;
char str[maxn];
int wx[maxn], wy[maxn];
int sx, sy, ex, ey, n;

int xDelta(char c) {
  if (c == 'L') return -1;
  if (c == 'R') return 1;
  return 0;
}
int yDelta(char c) {
  if (c == 'U') return 1;
  if (c == 'D') return -1;
  return 0;
}

bool check(LL mid) {
  LL k = mid / n;
  int t = mid % n;

  LL x = sx + k*wx[n] + wx[t], y = sy + k*wy[n] + wy[t];
  LL d = abs(ex - x) + abs(ey - y);
  return d <= mid;
}

int main()
{
  cin >> sx >> sy >> ex >> ey;
  cin >> n;
  cin >> (str+1);
  for (int i = 1; i <= n; ++i) {
    wx[i] = wx[i-1] + xDelta(str[i]);
    wy[i] = wy[i-1] + yDelta(str[i]);
  }

  LL l = 0, r = 1e14+1;
  while (l < r) {
    LL mid = (l + r) >> 1;
    if (check(mid)) r = mid;
    else l = mid+1;
  }
  if (l == 1e14+1) cout << -1 << endl;
  else cout << l << endl;
  return 0;
}
