#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 15;
LL f[maxn][maxn][maxn];  // f[i][j][k]: 第 i 位填 j 时, k 的数量

LL wPow(int a, int k) {
    LL res = 1;
    while (k -- ) res *= a;
    return res;
}

void init() {
    for (int i = 0; i <= 9; ++i) f[1][i][i] = 1;

    for (int i = 2; i < maxn; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; ++k) {
                for (int j2 = 0; j2 <= 9; ++j2) f[i][j][k] += f[i-1][j2][k];
                if (j == k) f[i][j][k] += wPow(10, i-1);
            }
        }
    }
} 

LL calc(vector<int>&nums, int pos) {
    LL res = 0;
    for (int i = pos; i >= 0; --i) res = res*10 + nums[i];
    return res;
}

LL dp(LL n, int k) {
    if (!n && !k) return 1;
    vector<int> nums;
    while (n) nums.push_back(n%10), n /= 10;

    LL res = 0;
    for (int i = (int)nums.size()-1; i >= 0; --i) {
        int x = nums[i];
        for (int j = 0; j < x; ++j) res += f[i+1][j][k];
        if (x == k) {
            LL t = calc(nums, i-1) + 1;
            res += t;
        }
    }

    if (!k) {
        for (int i = (int)nums.size()-1; i >= 1; --i) res -= wPow(10, i);
    }
    return res;
}

int main()
{
    init();
    LL l, r; cin >> l >> r;
    for (int i = 0; i <= 9; ++i) {
        cout << dp(r, i) - dp(l-1, i) << " ";
    }
    cout << endl;
    return 0;
}
