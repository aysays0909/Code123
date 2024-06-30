#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000 + 5;
int f[maxn][maxn], w[maxn];
vector<int> vec[maxn];

struct node {
  int x, y;
};

int bfs(int n, int u, int v) {
  queue<node> q; q.push({u, v}); f[u][v] = 0;
  while (!q.empty()) {
    node p = q.front(); q.pop();
    int x = p.x, y = p.y;
    if (x==n && y==1) return f[n][1];
    for (int i : vec[x]) {
      for (int j : vec[y]) {
        if (w[i]!=w[j] && f[i][j]==-1) {
          q.push({i, j}); f[i][j] = f[x][y]+1;
        }
      }
    }
  }
  return -1;
}

void solve() {
  memset(f, -1, sizeof(f));
  for (int i = 0; i < maxn; ++i) vec[i].clear();
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> w[i];
  while (m -- ) {
    int u, v; cin >> u >> v;
    vec[u].push_back(v), vec[v].push_back(u);
  }

  cout << bfs(n, 1, n) << endl;
}

int main()
{
  int T; cin >> T;
  while (T -- ) solve();
  return 0;
}
