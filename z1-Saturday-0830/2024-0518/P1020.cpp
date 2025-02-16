#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) { return a > b; }

int main() {
  vector<int> vv;
  int x;
  while (cin >> x) vv.push_back(x);

  vector<int> vec1, vec2;
  for (int i : vv) {
    if (vec1.empty() || i<=vec1.back()) vec1.push_back(i);
    else *upper_bound(vec1.begin(), vec1.end(), i, cmp) = i;

    if (vec2.empty() || i>vec2.back()) vec2.push_back(i);
    else *lower_bound(vec2.begin(), vec2.end(), i) = i;
  }

  cout << vec1.size() << endl;
  cout << vec2.size() << endl;
  return 0;
}
