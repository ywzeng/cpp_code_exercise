class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }
        // 利用对数性质，log(a^x) = xlog(a)
        // 那么如果n是4的x次方，则必须满足 log(n) == log(a^x) => log(n) == xlog(a) => x == log(n) / log(a)
        // 那么，如果log(n) / log(a)不是整数，则说明当前输入n，不是4的幂次方
        int x = log(n) / log(4);
        return x * log(4) == log(n);
    }
};
