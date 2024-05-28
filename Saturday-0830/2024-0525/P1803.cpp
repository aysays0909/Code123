#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
struct node {
  int l, r;
  bool operator < (const node& p) const { return r < p.r; }
} w[maxn];

int main() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) cin >> w[i].l >> w[i].r;
  sort(w+1, w+n+1);

  int res = 0;
  for (int i = 1, lst = -1; i <= n; ++i) {
    if (w[i].l >= lst) ++res, lst = w[i].r;
  }
  cout << res << endl;
  return 0;
}
