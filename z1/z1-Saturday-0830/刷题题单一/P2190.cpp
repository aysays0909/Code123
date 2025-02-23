#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
int w[maxn], f[maxn];

void update(int l, int r, int k) { f[l] += k, f[r+1] -= k; }

int main()
{
  int n, m; cin >> n >> m;
  while (m -- ) {
    int l, r, k; cin >> l >> r >> k;
    if (r >= l) update(l, r-1, k);
    else update(l, n, k), update(1, r-1, k);
  }

  int res = 0;
  for (int i = 1; i <= n; ++i) {
    f[i] += f[i-1];
    res = max(res, f[i]);
  }
  cout << (res-1)/36 + 1 << endl;
  return 0;
}
