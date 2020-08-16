#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void dfs(int curIndex, vector<int>& curAns, vector<int>& nums,
           vector<vector<int> >& ans) {
    ans.push_back(curAns);
    if (curIndex == nums.size()) {
      return;
    }

    for (int i = curIndex; i < nums.size(); i++) {
      vector<int> tmp = vector<int>(curAns);
      tmp.push_back(nums[i]);
      dfs(i + 1, tmp, nums, ans);
    }
  }
  vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> > ans;
    vector<int> curAns;
    dfs(0, curAns, nums, ans);
    return ans;
  }
};