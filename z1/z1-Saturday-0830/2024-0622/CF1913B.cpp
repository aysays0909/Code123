#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
char str[maxn];

void solve() {
  cin >> (str+1);
  int n = strlen(str+1);
  
  int cnt0 = 0, cnt1 = 0;
  for (int i = 1; i <= n; ++i) {
    if (str[i] == '1') cnt1++;
    else cnt0++;
  }
  
  for (int i = 1; i <= n; ++i) {
    if (str[i] == '1') cnt0--;
    else cnt1--;
    if (cnt0<0 || cnt1<0) {
      // i-1 没问题
      // 保留 i-1 个数
      // 删除 n - (i-1) 个数
      cout << n - (i-1) << endl;
      return;
    }
  }
  cout << 0 << endl;
}

int main()
{
  int T; cin >> T;
  while (T -- ) { solve(); }
  return 0;
}
