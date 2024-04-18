#include <bits/stdc++.h>

using namespace std;

const int maxn = 120 + 5;
int w[maxn][maxn], p[maxn][maxn];

int sum(int lx, int ly, int rx, int ry) {
  return p[rx][ry] - p[rx][ly-1] - p[lx-1][ry] + p[lx-1][ly-1];
}

int main()
{
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> w[i][j];
      p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + w[i][j];
    }
  }

  int res = 0;
  for (int i1 = 1; i1 <= n; ++i1) {
    for (int j1 = 1; j1 <= n; ++j1) {
      for (int i2 = i1; i2 <= n; ++i2) {
        for (int j2 = j1; j2 <= n; ++j2) {
          res = max(res, sum(i1,j1,i2,j2));
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}
