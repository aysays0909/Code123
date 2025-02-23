#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 60;
LL w[N], p[N];
bool f[N][N];

LL sum(int l, int r) { return p[r] - p[l-1]; }

bool check(int n, int m, LL res) {
  memset(f, false, sizeof(f));
  f[0][0] = true;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int i2 = 0; i2 <= i-1; ++i2) {
        if (f[i2][j-1] && (sum(i2+1,i)&res)==res) {
          f[i][j] = true;
        }
      }
    }
  }
  return f[n][m];
}

int main()
{
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> w[i], p[i] = p[i-1] + w[i];

  LL res = 0;
  for (int i = N; i >= 0; --i) {
    if (check(n, m, res|(1LL<<i))) {
      res |= (1LL<<i);
    }
  }
  cout << res << endl;
  return 0;
}
