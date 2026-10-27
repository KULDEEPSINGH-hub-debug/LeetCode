#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // dp[i][j] -> minimum edits needed to convert first i characters of s1(prefix of s1 of length i) to first j characters of s2
    // dp[i][0] = i -> have to delete all i chars
    // dp[0][j] = j -> have to insert j chars

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                int replace = dp[i-1][j-1];
                int delette = dp[i-1][j];
                int insert = dp[i][j-1];
                dp[i][j] = 1 + min({replace,delette,insert});  
                // The min({...}) form takes an initializer list and returns the smallest of all three values. It is part of <algorithm>
            }
        }
    }
    cout<<dp[n][m]<<"\n";
    return 0;
}