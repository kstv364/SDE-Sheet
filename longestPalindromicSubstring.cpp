class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n == 0)
            return "";

        if (n == 1)
            return s;
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }
        int start = 0, maxlen = 1, j;
        for (int l = 2; l <= n; l++)
        {
            for (int i = 0; i <= n - l; i++)
            {
                j = i + l - 1;
                if (l == 2 and s[i] == s[j])
                {
                    dp[i][j] = 1;
                }
                else if (s[i] == s[j] and dp[i + 1][j - 1] == 1)
                    dp[i][j] = 1;

                if (dp[i][j] == 1 and l >= maxlen)
                {
                    maxlen = l;
                    start = i;
                }
            }
        }
        return s.substr(start, maxlen);
    }
};