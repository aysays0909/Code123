#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e5 + 5;
char str[maxn];

void solve() {
  int n; cin >> n;
  cin >> (str+1);
  LL res = 0;

  int pos = n;
  for (int i = n; i >= 1; --i) {
    if (str[i] == '0') {
      res += pos-i;
      cout << res << " ";
      pos--;
    }
  }

  for (int i = pos; i >= 1; --i) cout << -1 << " ";
  cout << endl;
}

int main()
{
  int T; cin >> T;
  while (T -- ) solve();
  return 0;
}
