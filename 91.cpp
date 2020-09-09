class Solution {
public:
    int numDecodings(string s) 
    {
        // O(n) time | O(n) space
        vector<int> dp(1 + s.size(), -1);
        return helper(s, s.size(), dp);
    }
    
    int helper(string s, int n, vector<int>& dp) {
        
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];
        int answer = 0;
        if(s[n - 1] != '0') answer += helper(s, n - 1, dp);
        if(isvalidTwoDigit(s, n)) answer += helper(s, n - 2, dp);
        return dp[n] = answer;
    }
    
    bool isvalidTwoDigit(string s, int n){
        if(n == 1) return false;
        string temp = s.substr(n - 2, 2);
        if(temp >= "1" && temp <= "26") return true;
        return false;
    }
};
