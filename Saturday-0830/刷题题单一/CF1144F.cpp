#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
struct node {
  int u, v;
} w[maxn];
vector<int> vec[maxn];
int f[maxn];

bool dfs(int u, int fa, int v) {
  if (f[u] != -1) return f[u] == v;
  f[u] = v;
  for (int i : vec[u]) {
    if (i == fa) continue;
    if (!dfs(i, u, v^1)) return false;
  }
  return true;
}

int main()
{
  int n, m; cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    w[i] = {u, v};
    vec[u].push_back(v), vec[v].push_back(u);
  }

  memset(f, -1, sizeof(f));
  if (dfs(1, -1, 0)) {
    cout << "YES" << endl;
    for (int i = 1; i <= m; ++i) {
      if (f[w[i].u]) cout << 0;
      else cout << 1;
    }
    cout << endl;
  } else cout << "NO" << endl;
  return 0;
}
