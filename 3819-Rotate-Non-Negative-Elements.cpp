
class Solution {
private:
    void reverse(vector<int>& arr, int i, int j) {
        while (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> values;
        vector<int> indices;

        // Store non-negative values and their original positions
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                values.push_back(nums[i]);
                indices.push_back(i);
            }
        }

        if (values.empty())
            return nums;

        int n = values.size();
        k %= n;

        // Left rotate the non-negative values
        if (k > 0) {
            reverse(values, 0, n - 1);
            reverse(values, 0, n - k - 1);
            reverse(values, n - k, n - 1);
        }

        // Put rotated values back into original non-negative positions
        for (int i = 0; i < n; i++) {
            nums[indices[i]] = values[i];
        }

        return nums;
    }
};

