#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 3e5 + 5;
int w[maxn];
struct node {
  int to, value;
};
vector<node> vec[maxn];
LL f[maxn];

void dfs(int u, int fa, LL& ans) {
  f[u] = w[u];
  vector<LL> vv;
  for (node it : vec[u]) {
    if (it.to == fa) continue;
    dfs(it.to, u, ans);
    vv.push_back(f[it.to] - it.value);
  }
  sort(vv.begin(), vv.end()); reverse(vv.begin(), vv.end());
  LL res = f[u];
  for (int i = 0; i<(int)vv.size() && i<2; ++i) {
    if (vv[i] < 0) break;
    res += vv[i];
  }
  ans = max(ans, res);

  if (vv.size()>=1 && vv[0]>0) f[u] += vv[0];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; ++i) cin >> w[i];
  for (int i = 1; i <= n-1; ++i) {
    int u, v, value; cin >> u >> v >> value;
    vec[u].push_back({v, value}), vec[v].push_back({u, value});
  }

  LL ans = 0;
  dfs(1, -1, ans);
  cout << ans << endl;
  return 0;
}
