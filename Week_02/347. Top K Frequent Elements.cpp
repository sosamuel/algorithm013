#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct KVNode {
  int key;
  int val;

  KVNode(int k, int v) : key(k), val(v) {}
};

struct comparator {
  bool operator()(KVNode n1, KVNode n2) { return n1.val < n2.val; }
};
class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    vector<int> res;
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++) {
      hash[nums[i]] = hash.count(nums[i]) ? hash[nums[i]] + 1 : 1;
    }
    priority_queue<KVNode, vector<KVNode>, comparator> maxHeap;
    auto iter = hash.begin();
    for (auto iter = hash.begin(); iter != hash.end(); iter++) {
      KVNode *node = new KVNode(iter->first, iter->second);
      maxHeap.push(*node);
    }
    while (k--) {
      KVNode node = maxHeap.top();
      res.push_back(node.key);
      maxHeap.pop();
    }
    return res;
  }
};