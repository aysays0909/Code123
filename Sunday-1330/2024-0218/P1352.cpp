#include <bits/stdc++.h>

using namespace std;

const int maxn = 6e3 + 5;
int w[maxn], deg[maxn];
vector<int> vec[maxn];
int f[maxn][2];  // f[i][0]: 不选 i 的时候
                 // f[i][1]: 选 i 的时候

void dfs(int u) {
  for (int i : vec[u]) dfs(i);

  f[u][1] += w[u];
  for (int i : vec[u]) {
    f[u][1] += f[i][0];
    f[u][0] += max(f[i][0], f[i][1]);
  }
}

int main()
{
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) cin >> w[i];
  for (int i = 1; i <= n-1; ++i) {
    int u, v; cin >> u >> v;
    vec[v].push_back(u);
    deg[u]++;
  }

  for (int i = 1; i <= n; ++i) {
    if (!deg[i]) {
      dfs(i);
      cout << max(f[i][0], f[i][1]) << endl;
      break;
    }
  }
  return 0;
}
