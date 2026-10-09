class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int> mp;
        int ans = 0;
        int i = 0;
        int j = 0;
        int n = s.size();

        while(j < n) {
            if(mp.find(s[j]) != mp.end()) {
                ans = max(ans, j-i);

                while(i < j && mp.find(s[j]) != mp.end()) {
                    mp[s[i]]--;

                    if(mp[s[i]] == 0)
                        mp.erase(s[i]);

                    i++;
                }

                mp[s[j]]++;
                j++;
            }
            else {
                mp[s[j]]++;
                j++;
            }
        }

        return ans = max(ans, j-i);   

    }
};
