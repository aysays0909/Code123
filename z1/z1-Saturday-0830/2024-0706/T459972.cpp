#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e5 + 5;
int w[maxn];
LL p[maxn], pMax[maxn];

int main()
{
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) cin >> w[i];
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i-1] + w[i];
    pMax[i] = max(pMax[i-1], p[i]);
  }

  LL pos = 0, res = 0;
  for (int i = 1; i <= n; ++i) {
    res = max(res, pos + pMax[i]);
    pos += p[i];
  }
  cout << res << endl;
  return 0;
}
