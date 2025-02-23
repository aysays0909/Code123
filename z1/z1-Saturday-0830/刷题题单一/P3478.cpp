#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 1e6 + 5;
vector<int> vec[maxn];
int s[maxn];
LL f[maxn];

void dfs1(int u, int fa) {
  s[u] = 1;
  for (int i : vec[u]) {
    if (i == fa) continue;
    dfs1(i, u);
    s[u] += s[i];
    f[u] += f[i] + s[i];
  }
}

void dfs2(int u, int fa, int n) {
  for (int i : vec[u]) {
    if (i == fa) continue;
    f[i] += (f[u]-f[i]-s[i]) + (n-s[i]);
    dfs2(i, u, n);
  }
}

int main()
{
  int n; cin >> n;
  for (int i = 1; i <= n-1; ++i) {
    int u, v; cin >> u >> v;
    vec[u].push_back(v), vec[v].push_back(u);
  }
  dfs1(1, -1);
  dfs2(1, -1, n);

  LL maxx = 0; int id = 0;
  for (int i = 1; i <= n; ++i) {
    if (f[i] > maxx) {
      maxx = f[i], id = i;
    }
  }
  cout << id << endl;
  return 0;
}
