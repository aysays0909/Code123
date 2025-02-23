#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e5 + 5;
vector<int> vec[maxn];
int w[maxn], s[maxn];
LL f[maxn];

void dfs1(int u, int fa) {
  s[u] = 1;
  for (int i : vec[u]) {
    if (i == fa) continue;
    dfs1(i, u);
    s[u] += s[i];
    f[u] += f[i] + (LL)s[i]*(w[u]^w[i]);
  }
}

void dfs2(int u, int fa, int n) {
  for (int i : vec[u]) {
    if (i == fa) continue;
    f[i] += (f[u]-f[i]-(LL)s[i]*(w[u]^w[i])) + ((LL)n-s[i])*(w[u]^w[i]);
    dfs2(i, u, n);
  }
}

void solve() {
  int n; cin >> n;
  for (int i = 0; i <= n+2; ++i) {
    vec[i].clear();
    w[i] = s[i] = f[i] = 0;
  }
  for (int i = 1; i <= n; ++i) cin >> w[i];
  for (int i = 1; i <= n-1; ++i) {
    int u, v; cin >> u >> v;
    vec[u].push_back(v), vec[v].push_back(u);
  }

  dfs1(1, -1);
  dfs2(1, -1, n);

  for (int i = 1; i <= n; ++i) cout << f[i] << " ";
  cout << endl;
}

int main()
{
  int T; cin >> T;
  while (T -- ) { solve(); }
  return 0;
}
