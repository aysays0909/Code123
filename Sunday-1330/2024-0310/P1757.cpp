// 使用额外数组

#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 5, M = 100 + 5;
struct node {
  int v, c;
};
vector<node> vec[M];
int f[N], p[N];

int main()
{
  int m, n; cin >> m >> n;
  for (int i = 1; i <= n; ++i) {
    int a, b, c; cin >> a >> b >> c;
    vec[c].push_back({a, b});
  }
  
  for (int i = 1; i < M; ++i) {
  	memcpy(p, f, sizeof(p));
    for (node it : vec[i]) {
      for (int j = m; j >= it.v; --j) {
        f[j] = max(f[j], p[j-it.v] + it.c);
      }
    }
  }
  cout << f[m] << endl;
  return 0;
}
