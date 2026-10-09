class Solution {
public:
    int trap(vector<int>& h) {
        int i = 0;
        int j = 1;
        int n = h.size();
        int ans = 0;
        int block = 0;

        while (j < n) {

            while (j < n && h[i] > h[j]) {
                block += h[j];
                j++;
            }

            if (j < n) {
                int curr = min(h[i], h[j]) * (j - i - 1) - block;
                ans += max(0, curr);

                block = 0;
                i = j;
                j++;
            }
            
            else {
                int k = i + 1;

                while (k < n && h[k] <= h[i]) {
                    k++;
                }

                if (k == n) {
                    k = i + 1;
                    for (int x = i + 2; x < n; x++) {
                        if (h[x] > h[k])
                            k = x;
                    }
                }

                block = 0;
                for(int x = i + 1; x < k; x++)
                    block += h[x];

                int curr = min(h[i], h[k]) * (k - i - 1) - block;
                ans += max(0, curr);

                i = k;
                j = i + 1;
                block = 0;
            }
        }

        return ans;
    }
};