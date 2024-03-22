#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 50000 + 5, M = 500 + 5;
vector<int> vec[N];
int f[N][M];

void dfs(int u, int fa, int m, LL& ans) {
  f[u][0] = 1;
  vector<int> nums(m+1);
  for (int i : vec[u]) {
    if (i == fa) continue;
    dfs(i, u, m, ans);
    for (int j = 0; j < m; ++j) f[u][j+1] += f[i][j];
    for (int j = 0; j <= m-2; ++j) ans += f[i][j] * nums[m-2-j];
    for (int j = 0; j <= m-2; ++j) nums[j] += f[i][j];
  }

  ans += f[u][m];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 1; i <= n-1; ++i) {
    int u, v; cin >> u >> v;
    vec[u].push_back(v), vec[v].push_back(u);
  }

  LL ans = 0;
  dfs(1, -1, m, ans);
  cout << ans << endl;
  return 0;
}
