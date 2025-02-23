#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
int f[maxn];
struct node {
  int u, v, value;
  bool operator < (const node& p) const { return value < p.value; }
};

int fFind(int x) {
  if (f[x] != x) f[x] = fFind(f[x]);
  return f[x];
}

void kruskal(vector<node>& vec, int n) {
  sort(vec.begin(), vec.end());
  for (int i = 1; i <= n; ++i) f[i] = i;

  int sum = 0, cnt = 0;
  for (node it : vec) {
    int u = it.u, v = it.v, value = it.value;
    int pu = fFind(u), pv = fFind(v);
    if (pu == pv) continue;
    f[pu] = pv; sum += value; ++cnt;
  }
  if (cnt != n-1) cout << "orz" << endl;
  else cout << sum << endl;
}

int main()
{
  int n, m; cin >> n >> m;
  vector<node> vec;
  while (m -- ) {
    int u, v, value; cin >> u >> v >> value;
    vec.push_back({u, v, value});
  }
  kruskal(vec, n);
  return 0;
}
