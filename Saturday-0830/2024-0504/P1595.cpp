#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 20 + 5;
LL f[maxn];

int main()
{
  int n; cin >> n;
  f[1] = 0, f[2] = 1;
  for (int i = 3; i <= n; ++i) {
    f[i] = (i-1) * (f[i-1] + f[i-2]);
  }
  cout << f[n] << endl;
  return 0;
}
