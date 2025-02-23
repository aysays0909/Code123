#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
vector<int> vec[maxn];
int f[maxn][4], w[maxn];

void dfs(int u, int fa) {
  if (w[u]) f[u][w[u]] = 1;
  else f[u][1] = f[u][2] = f[u][3] = 1;

  for (int i : vec[u]) {
    if (i == fa) continue;
    dfs(i, u);
    for (int j = 1; j <= 3; ++j) {
      int res = 0;
      for (int k = 1; k <= 3; ++k) {
        if (j == k) continue;
        res = (res + f[i][k]) % mod;
      }
      f[u][j] = (LL)f[u][j] * res % mod;
    }
  }
}

int main()
{
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n-1; ++i) {
    int u, v; cin >> u >> v;
    vec[u].push_back(v), vec[v].push_back(u);
  }
  for (int i = 1; i <= m; ++i) {
    int b, c; cin >> b >> c; w[b] = c;
  }

  dfs(1, -1);

  int res = 0;
  for (int i = 1; i <= 3; ++i) res = (res + f[1][i]) % mod;
  cout << res << endl;
  return 0;
}
