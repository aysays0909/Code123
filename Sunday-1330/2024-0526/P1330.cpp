#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
vector<int> vec[maxn];
int col[maxn];

bool dfs(int u, int c, int& sum0, int& sum1) {
  if (col[u]) return col[u]==c;
  col[u] = c;
  if (c == 1) ++sum0;
  else ++sum1;
  for (int i : vec[u]) {
    if (!dfs(i, 3-c, sum0, sum1)) return false;
  }
  return true;
}

int main()
{
  int n, m; cin >> n >> m;
  while (m -- ) {
    int u, v; cin >> u >> v;
    vec[u].push_back(v), vec[v].push_back(u);
  }

  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (col[i]) continue;
    int sum0 = 0, sum1 = 0;
    if (!dfs(i, 1, sum0, sum1)) {
      res = -1; break;
    }
    res += min(sum0, sum1);
  }
  if (res == -1) cout << "Impossible" << endl;
  else cout << res << endl;
  return 0;
}
