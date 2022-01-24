class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0, end = 0;
        int maxCount = 0;
        int maxLen = 1;
        vector<int> freq(26, 0);
        for(end = 0; end<s.length(); end++)
        {
            freq[s[end]-'A']++;
            if(maxCount < freq[s[end]-'A'])
            {
               maxCount = freq[s[end]-'A'];
            }
            while(end - start + 1 - maxCount > k)
            {
                //when the window is in the invalid state
                freq[s[start]-'A']--; 
                start++;
                
                for(int i=0; i<26; i++)
                {
                    maxCount = max(maxCount, freq[i]);
                }
            }
            maxLen = max(maxLen, end-start+1);
        }
        return maxLen;
    }
};