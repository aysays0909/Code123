#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int fac[maxn], finv[maxn];

int qmod(int a, int k) {
  LL res = 1;
  while (k) {
    if (k & 1) res = (LL)res*a%mod;
    a = (LL)a * a % mod;
    k >>= 1;
  }
  return res;
}

void init() {
  fac[0] = finv[0] = 1;
  for (int i = 1; i < maxn; ++i) fac[i] = (LL)fac[i-1]*i % mod;
  for (int i = 1; i < maxn; ++i) finv[i] = qmod(fac[i], mod-2);
}

int C(int n, int m) {
  return (LL)fac[n] * finv[m] % mod * finv[n-m] % mod;
}

int main()
{
  init();
  int T; cin >> T;
  while (T -- ) {
    int n, m; cin >> n >> m;
    cout << C(n, m) << endl;
  }
  return 0;
}
