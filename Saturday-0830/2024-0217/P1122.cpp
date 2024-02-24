#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e4 + 5;
vector<int> vec[maxn];
LL w[maxn], f[maxn];

void dfs(int u, int fa) {
  f[u] = w[u];
  for (int i : vec[u]) {
    if (i == fa) continue;
    dfs(i, u);
    if (f[i] > 0) f[u] += f[i];
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

  dfs(1, -1);
  LL ans = -1e18;
  for (int i = 1; i <= n; ++i) ans = max(ans, f[i]);
  cout << ans << endl;
  return 0;
}
