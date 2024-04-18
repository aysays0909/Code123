#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 5;
int f[maxn];

struct node {
  int v, w;
};
vector<node> vec[maxn];

int main()
{
  int V, n; cin >> V >> n;
  while (n -- ) {
    int v, w, k; cin >> v >> w >> k;
    vec[k].push_back({v, w});
  }

  for (int i = 1; i < maxn; ++i) {
    for (int j = V; j >= 0; --j) {
      for (node it : vec[i]) {
        if (j - it.v >= 0) f[j] = max(f[j], f[j-it.v] + it.w);
      }
    }
  }
  cout << f[V] << endl;
  return 0;
}
