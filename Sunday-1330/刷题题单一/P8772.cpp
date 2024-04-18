#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e5 + 5;
int w[maxn];
LL p[maxn];

int main()
{
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) cin >> w[i], p[i] = p[i-1] + w[i];
  LL res = 0;
  for (int i = 2; i <= n; ++i) res += (LL)w[i] * p[i-1];
  cout << res << endl;
  return 0;
}
