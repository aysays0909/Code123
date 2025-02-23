#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 5;
const int mod = 998244353;
int f[maxn][4][maxn*2]; // f[i][j][k]: i行,状态j,有k个联通块的方案数

int value(int l, int j) {
  if (l == j) return 0;
  if (l==0 || l==3) return 1;
  if (j==0 || j==3) return 0;
  return 2;
}

int main()
{
  int n, m; cin >> n >> m;
  f[1][0][1] = f[1][3][1] = f[1][1][2] = f[1][2][2] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k <= m; ++k) {
        for (int l = 0; l < 4; ++l) {
          if (k-value(l,j) >= 0) f[i][j][k] = (f[i][j][k] + f[i-1][l][k-value(l,j)]) % mod;
        }
      }
    }
  }

  int res = 0;
  for (int i = 0; i < 4; ++i) res = (res + f[n][i][m]) % mod;
  cout << res << endl;
  return 0;
}
