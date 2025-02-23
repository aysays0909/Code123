#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

void solve() {
  int m, k, a1, ak; cin >> m >> k >> a1 >> ak;
  int res = 0;
  int x = m/k, y = m%k;

  if (a1 >= y) a1 -= y;
  else res += y-a1, a1 = 0;

  ak += a1/k;
  res += max(0, x-ak);
  cout << res << endl;
}

int main()
{
  int T; cin >> T;
  while (T -- ) solve();
  return 0;
}
