#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 + 5;
struct node {
  int to, value;
};
vector<node> vec[maxn];
int f[maxn][maxn];  // f[i][j]: 第i个点, 保留j根树枝

void dfs(int u, int fa, int m) {
  for (node it : vec[u]) {
    if (it.to == fa) continue;
    dfs(it.to, u, m);
    for (int i = m; i >= 0; --i) {
      for (int j = 0; j <= i-1; ++j) {
        f[u][i] = max(f[u][i], f[u][i-j-1] + f[it.to][j] + it.value);
      }
    }
  }
}

int main()
{
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n-1; ++i) {
    int u, v, w; cin >> u >> v >> w;
    vec[u].push_back({v, w}), vec[v].push_back({u, w});
  }
  dfs(1, -1, m);
  cout << f[1][m] << endl;
  return 0;
}
