#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e4 + 5;
int w[maxn];

bool check(int L, int n, int m, int mid) {
  int sum = 0;
  for (int i = 1, last = 0; i <= n+1; ++i) {
    if (w[i] - w[last] < mid) ++sum;
    else last = i;
  }
  return sum <= m;
}

int main()
{
  int L, n, m; cin >> L >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> w[i];
  sort(w+1, w+n+1);
  w[0] = 0, w[n+1] = L;

  int l = 1, r = 1e9;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(L, n, m, mid)) l = mid+1;
    else r = mid-1;
  }
  cout << r << endl;
  return 0;
}
