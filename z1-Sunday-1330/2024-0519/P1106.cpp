#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s; cin >> s;
  int k; cin >> k;

  vector<char> vec;
  for (char i : s) {
    while (k && (!vec.empty() && i<vec.back())) {
      vec.pop_back();
      --k;
    }
    vec.push_back(i);
  }

  while (k) { vec.pop_back(); --k; }

  bool flag = false;
  for (char i : vec) {
    if (i != '0') flag = true;
    if (flag) cout << i;
  }
  if (!flag) cout << 0;
  cout << endl;
  return 0;
}
