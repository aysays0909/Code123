#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 1e5 + 5;
struct node {
  int to, value;
};
vector<node> vec[maxn];
LL f[maxn];
int w[maxn], s[maxn];

void dfs1(int u, int fa) {
  s[u] = w[u];
  for (auto it : vec[u]) {
    if (it.to == fa) continue;
    int i = it.to, v = it.value;
    dfs1(i, u);
    s[u] += s[i];
    f[u] += f[i] + (LL)v * s[i];
  }
}

void dfs2(int u, int fa, int sum) {
  for (auto it : vec[u]) {
    if (it.to == fa) continue;
    int i = it.to, v = it.value;
    f[i] += (f[u]-f[i]-(LL)s[i]*v) + ((LL)sum-s[i])*v;
    dfs2(i, u, sum);
  }
}

int main()
{
  int n; cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; ++i) cin >> w[i], sum += w[i];
  for (int i = 1; i <= n-1; ++i) {
    int u, v, t; cin >> u >> v >> t;
    vec[u].push_back({v, t});
    vec[v].push_back({u, t});
  }

  dfs1(1, -1);
  dfs2(1, -1, sum);

  LL res = 1e18;
  for (int i = 1; i <= n; ++i) res = min(res, f[i]);
  cout << res << endl;
  return 0;
}
