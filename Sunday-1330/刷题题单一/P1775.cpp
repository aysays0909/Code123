#include <bits/stdc++.h>

using namespace std;

const int maxn = 300 + 5;
int w[maxn], p[maxn], f[maxn][maxn];

int sum(int l, int r) { return p[r] - p[l-1]; }

int main()
{
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i]; p[i] = p[i-1] + w[i];
  }

  memset(f, 0x3f, sizeof(f));
  for (int i = 1; i <= n; ++i) f[i][i] = 0;
  for (int len = 2; len <= n; ++len) {
    for (int i = 1; i+len-1 <= n; ++i) {
      int j = i+len-1;
      for (int k = i; k < j; ++k) {
        f[i][j] = min(f[i][j], f[i][k] + f[k+1][j] + sum(i, j));
      }
    }
  }
  cout << f[1][n] << endl;
  return 0;
}
