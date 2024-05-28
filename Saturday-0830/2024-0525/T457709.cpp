#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
struct node {
  int l, r;
  bool operator < (const node& p) const { return l < p.l; }
} w[maxn];

int main() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    int l, r; cin >> l >> r;
    w[i] = {l, r};
  }

  sort(w+1, w+n+1);
  priority_queue<int, vector<int>, greater<int>>q;
  for (int i = 1; i <= n; ++i) {
    if (!q.empty() && w[i].l>q.top()) q.pop();
    q.push(w[i].r);
  }
  cout << q.size() << endl;
  return 0;
}
