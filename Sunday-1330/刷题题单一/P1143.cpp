#include <bits/stdc++.h>

using namespace std;

int iValue(char c) {
  if (c >= '0' && c <= '9') return c-'0';
  return c-'A' + 10;
}

char cValue(int x) {
  if (x >= 0 && x <= 9) return x+'0';
  return x-10 + 'A';
}

int toTen(string s, int k) {
  int sum = 0, t = 1;
  reverse(s.begin(), s.end());
  for (char i : s) {
    int x = iValue(i);
    sum += x*t;
    t *= k;
  }
  return sum;
}

string toX(int n, int k) {
  string res;
  while (n) {
    int x = n%k;
    n /= k;
    res += cValue(x);
  }
  reverse(res.begin(), res.end());
  return res;
}

int main()
{
  int n, m; string s;
  cin >> n >> s >> m;
  cout << toX(toTen(s, n), m) << endl;
  return 0;
}
