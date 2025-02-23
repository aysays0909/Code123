#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 1e5 + 5;
int w[maxn], a[maxn];

void solve(int n) {
  for (int i = 1; i <= n; ++i) w[i] = a[i];

  LL m, ans = 0; cin >> m;
  for (int i = 62; i >= 0; --i) {
    LL sum = 0, limit = (1LL<<i);
    for (int j = 1; j <= n; ++j) {
      if (w[j] & limit) continue;
      sum += limit - w[j]%limit;
      if (sum > m) break;
    }
    if (sum > m) continue;

    m -= sum;
    ans += limit;
    for (int j = 1; j <= n; ++j) {
      if (w[j] & limit) continue;
      w[j] = limit;
    }
  }

  cout << ans << endl;
}

int main()
{
  int n, T; cin >> n >> T;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  while (T -- ) solve(n);
  return 0;
}
