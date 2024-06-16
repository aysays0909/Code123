#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e5 + 5;
int w[maxn], f[maxn], s[maxn];

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) cin >> w[i];

  for (int i = 1; i <= n; ++i) {
    if (w[i] > w[i-1]) f[i] = f[i-1] + 1;
    else f[i] = 1;
  }
  for (int i = n; i >= 1; --i) {
    if (w[i] < w[i+1]) s[i] = s[i+1] + 1;
    else s[i] = 1;
  }

  int res = 0;
  for (int i = 1; i <= n; ++i) res = max(res, f[i]);
  for (int i = 2; i <= n-1; ++i) {
    if (w[i+1] > w[i-1]) {
      res = max(res, f[i-1] + s[i+1]);
    }
  }
  cout << res << endl;
}

int main()
{
  int T = 1;
  while (T -- ) solve();
  return 0;
}
