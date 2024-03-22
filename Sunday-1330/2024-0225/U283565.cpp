#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
vector<int> vec[maxn];
int f[maxn];
int ans = 0;

void dfs(int u, int fa) {
  for (int i : vec[u]) {
    if (i == fa) continue;
    dfs(i, u);
    f[u] = max(f[u], f[i]);
  }
  f[u]++;
  ans = max(ans, f[u] - 1);

  vector<int> vv;
  for (int i : vec[u]) vv.push_back(f[i]);
  sort(vv.begin(), vv.end()); reverse(vv.begin(), vv.end());
  if (vv.size() >= 2) ans = max(ans, vv[0] + vv[1]);
}

int main()
{
  int n; cin >> n;
  for (int i = 1; i <= n-1; ++i) {
    int u, v; cin >> u >> v;
    vec[u].push_back(v), vec[v].push_back(u);
  }

  dfs(1, -1);
  cout << ans << endl;
  return 0;
}
