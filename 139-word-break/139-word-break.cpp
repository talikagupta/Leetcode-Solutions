class Solution {
public:
    int dp[301];
    int help(int i, string s, set<string>st)
    {
        if(i==s.size()) return 1;
        if(dp[i] != -1) return dp[i];
        string temp;
        for(int j=i; j<s.size(); j++)
        {
            temp+=s[j];
                if(st.find(temp) != st.end())
                {
                    if(help(j+1, s, st))
                    {
                        dp[i] = 1;
                        return dp[i];
                    }
                       
                }
        }
        dp[i] = 0;
        return dp[i];
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        memset(dp, -1, sizeof(dp));
        for(auto t : wordDict) st.insert(t);
        return help(0, s, st);
    }
};