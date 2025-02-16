#include <bits/stdc++.h>

using namespace std;

const int N = 225, M = 15;
const int mod = 10007;
char s[N][N], t[N][N];
int f[N][1<<M];
int n, m;

char cValue(int x) { return x+'0'; }

bool check(int i, int k) {
  for (int j = 0; j < m; ++j) {
    if (s[i][j] == '.') continue;
    if (s[i][j] != cValue((k>>j)&1)) return false;
  }
  return true;
}

bool isOk(int m, int k) {
  for (int i = 0; i < m-1; ++i) {
    if (((k>>i)&1) && ((k>>(i+1))&1)) return false;
  }
  return true;
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> s[i];

  if (n < m) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        t[j][n-i-1] = s[i][j];
      }
    }
    swap(n, m);
    memcpy(s, t, sizeof(s));
  }

  vector<int> vec;
  for (int i = 0; i < (1<<m); ++i) {
    if (isOk(m, i)) vec.push_back(i);
  }

  for (int i = 0; i < n; ++i) {
    for (int j : vec) {
      if (!check(i, j)) continue;
      if (i == 0) f[i][j] = 1;
      else {
        for (int k : vec) {
          if (j&k) continue;
          f[i][j] = (f[i][j] + f[i-1][k]) % mod;
        }
      }
    }
  }

  int res = 0;
  for (int i : vec) res = (res + f[n-1][i]) % mod;
  cout << res << endl;
  return 0;
}
