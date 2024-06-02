#include <bits/stdc++.h>

using namespace std;

const int maxn = 15;
int f[maxn][maxn];  // f[i][j]: 第 i 位填 j 时，一共有多少 windy 数

void init() {
    for (int i = 0; i <= 9; ++i) f[1][i] = 1;

    for (int i = 2; i < maxn; i++) {
        for (int j = 0; j <= 9; j++) {  // µÚ i Î»´æ j
            for (int j2 = 0; j2 <= 9; j2++) {
                if (abs(j-j2) >= 2) f[i][j] += f[i-1][j2];
            }
        }
    }
}

int dp(int n) {  // 1~n 中 windy 数的数量
    vector<int> nums;
    while (n) nums.push_back(n%10), n/=10;

    int res = 0, last = -2;
    for (int i = (int)nums.size()-1; i >= 0; i--) {
        int x = nums[i];
        for (int j = 0; j < x; j++) {
            if (i==(int)nums.size()-1 && !j) continue;
            if (abs(j-last)>=2) res += f[i+1][j];
        }
        if (abs(x-last) < 2) break;
        last = x;
        if (!i) ++res;
    }

    for (int i = (int)nums.size()-2; i >= 0; i--) {
        for (int j = 1; j <= 9; ++j) res += f[i+1][j];
    }
    return res;
}

int main()
{
    init();
    int l, r; cin >> l >> r;
    cout << dp(r) - dp(l-1) << endl;
    return 0;
}
