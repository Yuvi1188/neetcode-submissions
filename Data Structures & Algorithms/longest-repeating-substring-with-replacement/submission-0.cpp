class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        
        int r = k;
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        int maxFreq = 0;

        while(j < n) {
            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]);

            r = (j - i + 1) - maxFreq;

            if(r > k) {
                mp[s[i]]--;
                
                if(mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};
