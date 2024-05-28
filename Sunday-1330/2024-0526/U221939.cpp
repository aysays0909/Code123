#include <bits/stdc++.h>

using namespace std;

vector<int> ys;
int yFind(int x) { return lower_bound(ys.begin(), ys.end(), x) - ys.begin(); }

const int maxn = 3e5 + 5;
struct node {
  int x, c;
} w[maxn];
struct node2 {
  int l, r;
} q[maxn];
int p[maxn];

int sum(int l, int r) { return p[r] - p[l-1]; }

int main()
{
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int x, c; cin >> x >> c;
    w[i] = {x, c};
    ys.push_back(x);
  }
  for (int i = 1; i <= m; ++i) {
    int l, r; cin >> l >> r;
    q[i] = {l, r};
    ys.push_back(l), ys.push_back(r);
  }

  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());

  for (int i = 1; i <= n; ++i) {
    int x = w[i].x, c = w[i].c;
    int pos = yFind(x) + 1;
    p[pos] += c;
  }

  for (int i = 1; i < maxn; ++i) p[i] += p[i-1];

  for (int i = 1; i <= m; ++i) {
    int l = yFind(q[i].l)+1, r = yFind(q[i].r)+1;
    cout << sum(l, r) << endl;
  }
  return 0;
}
