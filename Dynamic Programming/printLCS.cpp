#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void lcs(string s1, string s2){
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 0; i <= m; i++) dp[0][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int res = dp[n][m];

    string ans = "";
    int i = n, j = m, index = res-1;
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            ans += s1[i-1];
            index--, i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    reverse(ans.begin(), ans.end());
    cout << "Length of LCS: " << res << endl;
    cout << "LCS (dummy string): " << ans << endl;
    
}

int main()
{
    string s1 = "abcde", s2 = "ace";
    lcs(s1,s2);
    return 0;
}