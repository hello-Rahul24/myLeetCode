class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }

        sort(diff.rbegin(), diff.rend());

        long long k = 1LL * k1 + k2;

        // If all differences can be reduced to zero
        long long total = 0;
        for (int d : diff) {
            total += d;
        }

        if (k >= total) {
            return 0;
        }

        for (int i = 0; i < n; i++) {
            long long curr = diff[i];
            long long next = (i + 1 < n) ? diff[i + 1] : 0;
            long long group = i + 1;

            long long cost = (curr - next) * group;

            if (k >= cost) {
                k -= cost;
                diff[i] = next;
            } else {
                long long reduction = k / group;
                long long rem = k % group;

                for (int j = 0; j <= i; j++) {
                    diff[j] = curr - reduction;
                }

                for (int j = 0; j < rem; j++) {
                    diff[j]--;
                }

                k = 0;
                break;
            }
        }

        long long ans = 0;

        for (int d : diff) {
            ans += 1LL * d * d;
        }

        return ans;
    }
};