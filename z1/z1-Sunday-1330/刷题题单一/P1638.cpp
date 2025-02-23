#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
int w[maxn], f[maxn];

int main()
{
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> w[i];

  int sum = 0;
  int res = 1e9, ll = -1, rr = -1;
  for (int i = 1, j = 0; i <= n; ++i) {
    j = max(j, i-1);
    while (j+1<=n && sum<m) {
      ++j;
      f[w[j]]++;
      if (f[w[j]] == 1) ++sum;
    }
    if (sum == m) {
      if (j-i+1 < res) {
        res = j-i+1;
        ll = i, rr = j;
      }
    }
    f[w[i]]--;
    if (f[w[i]] == 0) --sum;
  }
  cout << ll << " " << rr << endl;
  return 0;
}
