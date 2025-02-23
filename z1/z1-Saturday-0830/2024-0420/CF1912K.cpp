#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e5 + 5;
const int mod = 998244353;
int w[maxn], f[4][8];

int iValue(int x, int y) { return x*2 + y; }
int iValue(int x, int y, int z) { return x*4 + y*2 + z; }

int main()
{
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) cin >> w[i], w[i] &= 1;

  for (int i = 1; i <= n; ++i) {
    int a = f[2][iValue(0,0)] + f[3][iValue(0,0,0)];
    int b = f[2][iValue(0,1)] + f[3][iValue(1,0,1)];
    int c = f[2][iValue(1,0)] + f[3][iValue(1,1,0)];
    int d = f[2][iValue(1,1)] + f[3][iValue(0,1,1)];
    if (!w[i]) {
      f[3][iValue(0,0,0)] = ((LL)f[3][iValue(0,0,0)] + a) % mod;
      f[3][iValue(1,1,0)] = ((LL)f[3][iValue(1,1,0)] + d) % mod;
    } else {
      f[3][iValue(0,1,1)] = ((LL)f[3][iValue(0,1,1)] + b) % mod;
      f[3][iValue(1,0,1)] = ((LL)f[3][iValue(1,0,1)] + c) % mod;
    }

    f[2][iValue(0, w[i])] = (f[2][iValue(0, w[i])] + f[1][0]) % mod;
    f[2][iValue(1, w[i])] = (f[2][iValue(1, w[i])] + f[1][1]) % mod;

    f[1][w[i]]++;
  }

  int res = 0;
  res = (res + f[3][iValue(0,0,0)]) % mod;
  res = (res + f[3][iValue(1,1,0)]) % mod;
  res = (res + f[3][iValue(0,1,1)]) % mod;
  res = (res + f[3][iValue(1,0,1)]) % mod;
  cout << res << endl;
  return 0;
}
