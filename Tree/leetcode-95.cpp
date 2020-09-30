// 给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

// 示例：

// 输入：3
// 输出：
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// 解释：
// 以上的输出对应以下 5 种不同结构的二叉搜索树：

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/unique-binary-search-trees-ii


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (!n) {
            return {};
        }
        return buildtree(1, n);
    }
    vector<TreeNode*> buildtree(int l, int r) {
        if (l > r) {
            return { nullptr };
        }
        vector<TreeNode*> res;
        for (int i = l; i <= r; i++) {
            vector<TreeNode*> ll = buildtree(l, i - 1);
            vector<TreeNode*> rr = buildtree(i + 1, r);
            for (int li = 0; li < ll.size(); li++) {
                for (int ri = 0; ri < rr.size(); ri++) {
                    TreeNode *root = new TreeNode(i);
                    root -> left = ll[li];
                    root -> right = rr[ri];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
