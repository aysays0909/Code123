#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
vector<int> vec[maxn];
int w[maxn], f[maxn];

void dfs1(int u, int fa) {
  f[u] = (w[u]==1?1:-1);
  for (int i : vec[u]) {
    if (i == fa) continue;
    dfs1(i, u);
    f[u] += max(f[i], 0);
  }
}

void dfs2(int u, int fa) {
  for (int i : vec[u]) {
    if (i == fa) continue;
    if (f[i] > 0) f[i] += max(0, f[u]-f[i]);
    else f[i] += max(0, f[u]);
    dfs2(i, u);
  }
}

int main()
{
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) cin >> w[i];
  for (int i = 1; i <= n-1; ++i) {
    int u, v; cin >> u >> v;
    vec[u].push_back(v), vec[v].push_back(u);
  }

  dfs1(1, -1);
  dfs2(1, -1);

  for (int i = 1; i <= n; ++i) cout << f[i] << " ";
  cout << endl;
  return 0;
}
