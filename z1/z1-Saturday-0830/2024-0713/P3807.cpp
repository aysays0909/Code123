#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e5 + 5;
int fac[maxn], iFac[maxn];

int qmod(int a, int k, int p) {
  int res = 1;
  while (k) {
    if (k & 1) res = (LL)res * a % p;
    a = (LL)a * a % p;
    k >>= 1;
  }
  return res;
}

int C(int n, int m, int p) {
  if (n < m) return 0;
  return (LL)fac[n] * iFac[m] % p * iFac[n-m] % p;
}

int Lucas(int n, int m, int p) {
  if (m == 0) return 1;
  return (LL)Lucas(n/p, m/p, p) * C(n%p, m%p, p) % p;
}

void solve() {
  int n, m, p; cin >> n >> m >> p;
  fac[0] = iFac[0] = 1;
  for (int i = 1; i < maxn; ++i) fac[i] = (LL)fac[i-1] * i % p;
  for (int i = 1; i < maxn; ++i) iFac[i] = qmod(fac[i], p-2, p);

  cout << Lucas(n+m, n, p) << endl;
}

int main()
{
  int T; cin >> T;
  while (T -- ) solve();
  return 0;
}
