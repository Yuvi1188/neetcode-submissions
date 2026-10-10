
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        int n = s.size();
        for(int i = 0; i < t.size(); i++){
            mp1[t[i]]++;
        }

        int left = 0;
        int right = 0;
        int st = -1;
        int en = -1;
        int ans = INT_MAX;

        while(right < n){
            if(mp1.find(s[right]) != mp1.end()){
                mp2[s[right]]++;
            }

            while(left <= right) {
                bool valid = true;

                for(auto it : mp1){
                    if(mp2[it.first] < it.second){
                        valid = false;
                        break;
                    }
                }

                if(!valid) break;

                if(ans > (right - left + 1)){
                    ans = right - left + 1;
                    st = left;
                    en = right;
                }

                mp2[s[left]]--;
                if(mp2[s[left]] == 0){
                    mp2.erase(s[left]);
                }
                left++;
            }
            right++;
        }

        if(st == -1) return "";
        return s.substr(st, en - st + 1);
    }
};
