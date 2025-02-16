#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5, N = 8;
int w[maxn][N];

bool check(int n, int m, int mid, int& ansL, int& ansR) {
  int f[1<<N];
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; ++i) {
    int res = 0;
    for (int j = 0; j < m; ++j) {
      if (w[i][j] >= mid) res |= (1<<j);
    }
    f[res] = i;
  }

  for (int i = 0; i < (1<<m); ++i) {
    for (int j = 0; j < (1<<m); ++j) {
      if ((i|j)==(1<<m)-1 && f[i] && f[j]) {
        ansL = f[i], ansR = f[j];
        return true;
      }
    }
  }
  return false;
}

int main()
{
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < m; ++j) cin >> w[i][j];
  }

  int l = 0, r = 1e9;
  int ansL = 1, ansR = 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(n, m, mid, ansL, ansR)) l = mid+1;
    else r = mid-1;
  }
  cout << ansL << " " << ansR << endl;
  return 0;
}
