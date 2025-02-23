#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 + 5;
const int inf = 0x3f3f3f3f;
int w[maxn][maxn], f[maxn][maxn];

int main()
{
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> w[i][j];
      f[i][j] = (w[i][j]==1);
    }
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        f[i][j] |= (f[i][k] && f[k][j]);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (f[i][j]) cout << 1 << " ";
      else cout << 0 << " ";
    }
    cout << endl;
  }
  return 0;
}
