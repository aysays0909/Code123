#include <bits/stdc++.h>

using namespace std;

const int maxn = 300 + 5;
vector<int> vec[maxn];
int w[maxn], f[maxn][maxn];

void dfs(int u, int m) {
  f[u][1] = w[u];
  for (int i : vec[u]) {
    dfs(i, m);
    for (int j = m; j >= 0; --j) {
      for (int k = 1; k < j; ++k) f[u][j] = max(f[u][j], f[u][j-k] + f[i][k]);
    }
  }
}

int main()
{
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x >> w[i];
    vec[x].push_back(i);
  }
  dfs(0, m+1);
  cout << f[0][m+1] << endl;
  return 0;
}