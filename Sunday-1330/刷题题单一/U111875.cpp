#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int w[N][N], f[1<<N][N];

int main()
{
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cin >> w[i][j];
  }

  memset(f, 0x3f, sizeof(f));
  f[1][0] = 0;
  for (int i = 2; i < (1<<n); ++i) {
    for (int j = 0; j < n; ++j) {
      if (!((i>>j) & 1)) continue;
      for (int k = 0; k < n; ++k) {
        if (j == k) continue;
        if (!((i>>k) & 1)) continue;
        f[i][j] = min(f[i][j], f[i-(1<<j)][k] + w[k][j]);
      }
    }
  }
  cout << f[(1<<n)-1][n-1] << endl;
  return 0;
}
