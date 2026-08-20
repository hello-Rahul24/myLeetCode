class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> array1;
        vector<int> array2;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                array1.push_back(nums[i]);
                continue;
            }
            if (i == 1){
                array2.push_back(nums[i]);
                continue;
            }
            // after adding first two elements to two arrays
            int lastelofarr1 = array1.back();
            int lastelofarr2 = array2.back();
            if (lastelofarr1 > lastelofarr2) {
                array1.push_back(nums[i]);
            } else {
                array2.push_back(nums[i]);
            }
        }
        for (int i = 0; i < array2.size(); i++) {
            array1.push_back(array2[i]);
        }

        return array1;
    }
    //this is optimal solution cause this has tc => O(n) which can not be furthar reduced
    //space complexity is O(n) it is also optimal cause we can not do it in constant space 
    // Could we use only one result array and avoid array2? Not straightforwardly, because the final answer must be:array1 elements + array2 elements and while processing, you don't yet know where the array2 elements will appear in the final vector.
};