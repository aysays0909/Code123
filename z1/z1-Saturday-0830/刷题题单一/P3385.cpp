#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e3 + 5;
const int inf = 0x3f3f3f3f;
struct node {
  int to, value;
};
vector<node> vec[maxn];
bool vis[maxn];
int dis[maxn], cnt[maxn];

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    vec[i].clear();
    vis[i] = false, dis[i] = inf, cnt[i] = 0;
  }

  while (m -- ) {
    int u, v, w; cin >> u >> v >> w;
    vec[u].push_back({v, w});
    if (w >= 0) vec[v].push_back({u, w});
  }

  bool flag = false;
  queue<int> q; q.push(1); vis[1] = true, dis[1] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    vis[u] = false;
    ++cnt[u];
    if (cnt[u] >= n) { flag = true; break; }
    for (node it : vec[u]) {
      int i = it.to, d = it.value;
      if (dis[i] > dis[u]+d) {
        dis[i] = dis[u] + d;
        if (!vis[i]) {
          q.push(i); vis[i] = true;
        }
      }
    }
  }

  cout << (flag ? "YES" : "NO") << endl;
}

int main()
{
  int T; cin >> T;
  while (T -- ) solve();
  return 0;
}
