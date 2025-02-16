#include <bits/stdc++.h>

using namespace std;

bool match(string s, string t) {
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  return s==t;
}

int main()
{
  int n; cin >> n;
  string s, t; cin >> s >> t;
  if (!match(s, t)) { cout << -1 << endl; return 0; }

  for (int i=n-1, j=n-1; j>=0; --j) {
    if (s[i] == t[j]) --i;
    if (!j) cout << i+1 << endl;
  }
  return 0;
}
