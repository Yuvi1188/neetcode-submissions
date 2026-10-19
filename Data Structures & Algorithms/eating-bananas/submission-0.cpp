class Solution {
public:
    int solve(vector<int>& piles, int num, int h) {
        int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += (piles[i] + num - 1) / num;
        }
        return hours - h;
   }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
         int maxNum = INT_MIN;
         for(int i =0;i<n;i++){
            maxNum = max(maxNum, piles[i]);
         } 
        int left = 1;
        int right = maxNum;

        int ans  = maxNum;

        while(left<=right){
           int mid = left +(right-left)/2;
           int currLeftBanana = solve(piles, mid, h);
           if(currLeftBanana<=0){
             ans  = mid;
             right =  mid-1;
           }
           else{
             left  = mid+1;
           }
        }
        return ans;
    }
};
