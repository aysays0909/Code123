#include <bits/stdc++.h>

using namespace std;

const int maxn = 3000 + 5;
const int inf = 0x3f3f3f3f;
struct edge {
  int to, value;
};
vector<edge> vec[maxn];
int w[maxn], f[maxn][maxn], s[maxn];

void dfs(int u, int n, int m) {
  s[u] = 1;
  if (u >= n-m+1) { f[u][1] = w[u]; return; }
  for (edge it : vec[u]) { dfs(it.to, n, m); s[u] += s[it.to]; }

  for (int j = min(s[u], m); j >= 1; --j) f[u][j] = -inf;

  for (edge it : vec[u]) {
    int i = it.to, v = it.value;
    for (int j = min(s[u], m); j >= 1; --j) {
      for (int k = 1; k <= min(s[i], j); ++k) {
        f[u][j] = max(f[u][j], f[u][j-k] + f[i][k] - v);
      }
    }
  }
}

int main()
{
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n-m; ++i) {
    int k; cin >> k;
    while (k -- ) {
      int to, value; cin >> to >> value;
      vec[i].push_back({to, value});
    }
  }
  for (int i = n-m+1; i <= n; ++i) cin >> w[i];
  dfs(1, n, m);
  for (int i = m; i >= 0; --i) {
    if (f[1][i] >= 0) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
