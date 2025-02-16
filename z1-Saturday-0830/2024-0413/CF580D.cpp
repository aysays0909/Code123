#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 19;
int w[N];
int a[N][N];
LL f[1<<N][N];

int main()
{
  int n, m, k; cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) cin >> w[i];
  for (int i = 1; i <= k; ++i) {
    int x, y, c; cin >> x >> y >> c;
    a[x-1][y-1] = c;
  }

  for (int i = 0; i < n; ++i) f[(1<<i)][i] = w[i];
  for (int i = 1; i < (1<<n); ++i) {
    for (int j = 0; j < n; ++j) {
      if ((i>>j) & 1) {  // f[i][j]
        for (int k = 0; k < n; ++k) {
          if (j == k) continue;
          if ((i>>k) & 1) {
            f[i][j] = max(f[i][j], f[i-(1<<j)][k] + a[k][j] + w[j]);
          }
        }
      }
    }
  }

  LL res = 0;
  for (int i = 1; i < (1<<n); ++i) {
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      if ((i>>j) & 1) ++cnt;
    }
    if (cnt == m) {
      for (int j = 0; j < n; ++j) {
        if ((i>>j) & 1) res = max(res, f[i][j]);
      }
    }
  }
  cout << res << endl;
  return 0;
}
