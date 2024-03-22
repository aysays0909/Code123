// 不适用额外数组

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 1000 + 5;
LL f[maxn];

struct node {
  int v, c;
};
vector<node> vec[105];

int main()
{
  int m, n; cin >> m >> n;
  for (int i = 1; i <= n; ++i) {
    int a, b, c; cin >> a >> b >> c;
    vec[c].push_back({a, b});
  }

  for (int i = 1; i <= 100; ++i) {
    for (int j = m; j >= 1; --j) {
      for (node it : vec[i]) {
        if (j >= it.v) f[j] = max(f[j], f[j-it.v] + it.c);
      }
    }
  }
  cout << f[m] << endl;
  return 0;
}
