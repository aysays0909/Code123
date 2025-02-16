#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e6 + 5;
int w[maxn], f[maxn];

int main()
{
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) cin >> w[i];
  stack<int> s;
  for (int i = n; i >= 1; --i) {
    while (!s.empty() && w[i] >= w[s.top()]) s.pop();
    if (!s.empty()) f[i] = s.top();
    else f[i] = 0;
    s.push(i);
  }
  for (int i = 1; i <= n; ++i) cout << f[i] << " ";
  cout << endl;
  return 0;
}
