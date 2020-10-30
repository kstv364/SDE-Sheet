#include <bits/stdc++.h>
using namespace std;

// Palindromic substring
void solve(string s, int n)
{
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    int start = 0, len = 1, maxlen = 1;
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int cl = 2; cl <= n; cl++)
    {
        for (int i = 0; i < n - cl + 1; i++)
        {
            int j = i + cl - 1;

            // can only be palindrome if substring is or length 2
            if (s[i] == s[j] and (cl == 2 or dp[i + 1][j - 1] == 1))
            {
                len = j - i + 1;
                dp[i][j] = 1;
                if (len > maxlen)
                {
                    maxlen = len;
                    start = i;
                }
            }
        }
    }
    cout << s.substr(start, maxlen) << endl;
}

void testcase()
{
    string s;
    cin >> s;
    solve(s, s.length());
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        testcase();
    }
    return 0;
}