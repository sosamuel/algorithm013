// 将数组右边一部分移到左边:
// 1. 左边反转
// 2. 右边反转
// 3. 全部反转
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};

