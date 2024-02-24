#include <bits/stdc++.h>

using namespace std;

const int maxn = 1500 + 5;
vector<int> vec[maxn];
int f[maxn][2];

void dfs(int u, int fa) {
  f[u][1] = 1;
  for (int i : vec[u]) {
    if (i == fa) continue;
    dfs(i, u);
    f[u][0] += f[i][1];
    f[u][1] += min(f[i][0], f[i][1]);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    int id; cin >> id;
    int m; cin >> m;
    while (m -- ) {
      int x; cin >> x;
      vec[id].push_back(x), vec[x].push_back(id);
    }
  }

  dfs(1, -1);
  cout << min(f[1][0], f[1][1]) << endl;
  return 0;
}
