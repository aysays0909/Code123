#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 + 5;
vector<int> vec[maxn];
int deg[maxn];

int main()
{
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    while (cin >> x) {
      if (!x) break;
      vec[i].push_back(x);
      deg[x]++;
    }
  }

  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (!deg[i]) q.push(i);
  }

  while (!q.empty()) {
    int u = q.front(); q.pop();
    cout << u << " ";
    for (int i : vec[u]) {
      deg[i]--;
      if (!deg[i]) q.push(i);
    }
  }
  cout << endl;
  return 0;
}
