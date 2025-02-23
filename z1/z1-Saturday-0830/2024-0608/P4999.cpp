#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 20;
const int mod = 1e9+7;
int f[maxn][maxn];  // f[i][j]: 第 i 位填 j 时, 总数字和是多少

int wPow(int a, int k) {
  int res = 1;
  while (k -- ) res = (LL)res*a % mod;
  return res;
}

void init() {
  for (int i = 0; i <= 9; ++i) f[1][i] = i;
  for (int i = 2; i < maxn; ++i) {
    for (int j = 0; j <= 9; ++j) {
      for (int k = 0; k <= 9; ++k) f[i][j] = (f[i][j] + f[i-1][k]) % mod;
      f[i][j] = (f[i][j] + (LL)j*wPow(10, i-1)) % mod;
    }
  }
}

int calc(vector<int>& nums, int pos) {
  int res = 0;
  for (int i = pos; i >= 0; --i) res = ((LL)res*10 + nums[i]) % mod;
  return res;
}

int dp(LL n) {
  vector<int> nums;
  while (n) nums.push_back(n%10), n /= 10;

  int res = 0;
  for (int i = (int)nums.size()-1; i >= 0; --i) {
    int x = nums[i];
    for (int j = 0; j < x; ++j) res = (res + f[i+1][j]) % mod;
    int t = calc(nums, i-1) + 1;
    res = (res + (LL)x*t) % mod;
  }
  return res;
}

int main()
{
  init();
  int T; cin >> T;
  while (T -- ) {
    LL l, r; cin >> l >> r;
    cout << (dp(r) - dp(l-1) + mod) % mod << endl;
  }
  return 0;
}
