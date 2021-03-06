#include <iostream>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

/**
 * BFS
 * 维护任务队列
 * 每次取队首任务处理, 并增加新任务于队尾
 **/

class Solution {
 public:
  vector<vector<int> > levelOrder(Node* root) {
    vector<vector<int> > res;
    if (root == NULL) return res;
    vector<vector<Node*> > queue;
    vector<Node*> firstTasks;
    firstTasks.push_back(root);
    queue.push_back(firstTasks);
    while (!queue.empty()) {
      //   get tasks
      vector<Node*> tasks = queue[0];
      queue.erase(queue.begin());
      if (tasks.empty()) continue;
      vector<int> ans;
      vector<Node*> newTasks;
      //   process tasks
      for (vector<Node*>::iterator iter = tasks.begin(); iter != tasks.end();
           iter++) {
        //   process data
        ans.push_back((*iter)->val);
        vector<Node*> childs = (*iter)->children;
        if (childs.empty()) continue;
        // add new task
        for (auto itr = childs.begin(); itr != childs.end(); itr++) {
          newTasks.push_back((*itr));
        }
      }
      queue.push_back(newTasks);
      if (!ans.empty()) res.push_back(ans);
    }
    return res;
  }
};