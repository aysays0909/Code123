#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
struct node {
  int to, value;
  bool operator < (const node& p) const { return value < p.value; }
  bool operator > (const node& p) const { return value > p.value; }
};
int d[maxn];
vector<node> vec[maxn];
bool vis[maxn];

void dijkstra(int s) {
  priority_queue<node, vector<node>, greater<node>>q;
  q.push({s, 0});
  while (!q.empty()) {
    node p = q.top(); q.pop();
    int u = p.to, ll = p.value;
    if (vis[u]) continue;
    vis[u] = true; d[u] = ll;
    for (node it : vec[u]) {
      int v = it.to, dis = it.value;
      if (d[v] > ll+dis) {
        q.push({v, ll+dis});
      }
    }
  }
}

int main()
{
  memset(d, 0x3f, sizeof(d));
  int n, m, s; cin >> n >> m >> s;
  while (m -- ) {
    int u, v, s; cin >> u >> v >> s;
    vec[u].push_back({v, s});
  }

  dijkstra(s);
  for (int i = 1; i <= n; ++i) cout << d[i] << " ";
  cout << endl;
  return 0;
}
