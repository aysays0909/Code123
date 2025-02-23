#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
vector<int> vec[maxn];
int f[maxn];
int ans = 0;

void dfs(int u, int fa) {
  f[u] = 1;
  for (int i : vec[u]) {
    if (i == fa) continue;
    dfs(i, u);
    f[u] += f[i];
  }
  if (f[u] % 2 == 0) ++ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n-1; ++i) {
    int u, v; cin >> u >> v;
    vec[u].push_back(v), vec[v].push_back(u);
  }
  if (n & 1) { cout << -1 << endl; return 0; }

  dfs(1, -1);

  cout << ans - 1 << endl;
  return 0;
}
