#include <bits/stdc++.h>

using namespace std;

const int N = 40 + 5, M = 6;
int f[N][1<<M][1<<M];
// f[i, j, k]:  i ~ j,  i-1 ~ k

bool check(int n, int m, int i, int j, int k, int l) {
  // i: j  i-1: k  i-2: l
  if (i-2==0 && l) return false;
  if (i==n+1 && j) return false;
  for (int p = 0; p < m; ++p) {
    if (!((k>>p) & 1)) {
      if ((j>>p) & 1) continue;
      if ((l>>p) & 1) continue;
      if (p>0 && ((k>>(p-1)) & 1)) continue;
      if (p<m && ((k>>(p+1)) & 1)) continue;
      return false;
    }
  }
  return true;
}

int sum(int k, int m) {
  int res = 0;
  for (int i = 0; i < m; ++i) {
    if (!((k>>i) & 1)) ++res;
  }
  return res;
}

int main()
{
  int n, m; cin >> n >> m;
  if (n < m) swap(n, m);

  int res = 0;
  for (int i = 2; i <= n+1; ++i) {
    for (int j = 0; j < (1<<m); ++j) {
      for (int k = 0; k < (1<<m); ++k) {
        for (int l = 0; l < (1<<m); ++l) {
          // i: j  i-1: k  i-2: l
          if (check(n, m, i, j, k, l)) {
            f[i][j][k] = max(f[i][j][k], f[i-1][k][l] + sum(k, m));
            if (i == n+1) res = max(res, f[i][j][k]);
          }
        }
      }
    }
  }

  cout << res << endl;
  return 0;
}
