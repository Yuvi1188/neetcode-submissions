
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp1, mp2;

        int n = s.size();

        for(int i = 0; i < t.size(); i++){
            mp1[t[i]]++;
        }

        int left = 0, right = 0;
        int st = -1, en = -1;
        int ans = INT_MAX;

        int formed = 0;
        int required = mp1.size();

        while(right < n){

            if(mp1.find(s[right]) != mp1.end()){
                mp2[s[right]]++;

                if(mp2[s[right]] == mp1[s[right]]){
                    formed++;
                }
            }

            while(formed == required){
                if(ans > right - left + 1){
                    ans = right - left + 1;
                    st = left;
                    en = right;
                }

                if(mp1.find(s[left]) != mp1.end()){
                    if(mp2[s[left]] == mp1[s[left]]){
                        formed--;
                    }

                    mp2[s[left]]--;
                }

                left++;
            }

            right++;
        }

        if(st == -1) return "";
        return s.substr(st, en - st + 1);
    }
};
