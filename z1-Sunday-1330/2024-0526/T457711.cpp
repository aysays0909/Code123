#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 1e5 + 5;
char str[maxn];
int p1[maxn], s3[maxn];

int main() {
  int n; cin >> n;
  cin >> (str+1);
  for (int i = 1; i <= n; ++i) p1[i] = p1[i-1] + (str[i]=='1');
  for (int i = n; i >= 1; --i) s3[i] = s3[i+1] + (str[i]=='3');

  LL res = 0, add1 = 0, add2 = 0, add3 = 0;
  for (int i = 1; i <= n; ++i) {
    if (str[i] == '2') {
      res += (LL)p1[i-1] * s3[i+1];
      add1 += s3[i+1], add3 += p1[i-1];
    }
    add2 = max(add2, (LL)p1[i-1]*s3[i]);
  }

  cout << res + max({add1, add2, add3}) << endl;
  return 0;
}
