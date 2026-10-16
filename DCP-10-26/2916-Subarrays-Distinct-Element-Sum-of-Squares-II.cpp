
class Solution {
public:
    const long long MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sqSum = 0;
        long long lazy = 0;
    };

    vector<Node> seg;
    int n;

    void apply(int node, int l, int r, long long x) {
        long long len = r - l + 1;

        seg[node].sqSum =
            (seg[node].sqSum
             + 2 * x % MOD * seg[node].sum % MOD
             + x * x % MOD * len % MOD) % MOD;

        seg[node].sum =
            (seg[node].sum + x * len) % MOD;

        seg[node].lazy =
            (seg[node].lazy + x) % MOD;
    }

    void push(int node, int l, int r) {
        if (seg[node].lazy == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;
        long long lazy = seg[node].lazy;

        apply(node * 2, l, mid, lazy);
        apply(node * 2 + 1, mid + 1, r, lazy);

        seg[node].lazy = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr, long long x) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, x);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr, x);
        update(node * 2 + 1, mid + 1, r, ql, qr, x);

        seg[node].sum =
            (seg[node * 2].sum +
             seg[node * 2 + 1].sum) % MOD;

        seg[node].sqSum =
            (seg[node * 2].sqSum +
             seg[node * 2 + 1].sqSum) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);

        unordered_map<int, int> lastSeen;

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int last = -1;

            if (lastSeen.count(nums[i])) {
                last = lastSeen[nums[i]];
            }

            // Distinct counts increase by 1
            // for starting indices [last + 1, i].
            update(1, 0, n - 1, last + 1, i, 1);

            // Sum of squares for all subarrays
            // ending at index i.
            ans = (ans + seg[1].sqSum) % MOD;

            lastSeen[nums[i]] = i;
        }

        return ans;
    }
};
