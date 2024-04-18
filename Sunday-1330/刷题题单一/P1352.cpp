#include <bits/stdc++.h>

using namespace std;

const int maxn = 6000 + 5;
int w[maxn], deg[maxn], f[maxn][2];
vector<int> vec[maxn];

void dfs(int u) {
  f[u][1] = w[u];
  for (int i : vec[u]) {
    dfs(i);
    f[u][1] += f[i][0];
    f[u][0] += max(f[i][0], f[i][1]);
  }
}

int main()
{
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) cin >> w[i];
  for (int i = 1; i <= n-1; ++i) {
    int x, y; cin >> x >> y;
    vec[y].push_back(x);
    deg[x]++;
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
