/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 */

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

#include <utility>
class Node {
public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = nullptr;
    topRight = nullptr;
    bottomLeft = nullptr;
    bottomRight = nullptr;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = nullptr;
    topRight = nullptr;
    bottomLeft = nullptr;
    bottomRight = nullptr;
  }

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight,
       Node *_bottomLeft, Node *_bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

#include <vector>

using namespace std;
class Solution {
public:
  pair<int, bool> isLeaf(vector<vector<int>> &grid, int startRow, int startCol, int gridSize) {
    int val = -1;
    for (int i = startRow; i < startRow + gridSize; i++) {
      for (int j = startCol; j < startCol + gridSize; j++) {
        if (val == -1) {
          val = grid[i][j];
        } else if (grid[i][j] != val) {
          return {val, false};
        }
      }
    }
    return {val, true};
  }
  Node *helper(vector<vector<int>> &grid, int startRow, int startCol, int subgridSize) {
    // get the four grids.
    // for each grid, decide whether to recurse or not
    Node *curr = new Node();
    auto [val, isCurrLeaf] = isLeaf(grid,  startRow, startCol, subgridSize);
    if (isCurrLeaf) {
      curr->isLeaf = true;
      curr->val = val;
      return curr;
    }
    curr->isLeaf = false;
    curr->val = 0;
    curr->topLeft = helper(grid, startRow, startCol, subgridSize / 2);
    curr->topRight = helper(grid, startRow, startCol + subgridSize / 2, subgridSize / 2);
    curr->bottomLeft = helper(grid, startRow + subgridSize / 2, startCol, subgridSize / 2);
    curr->bottomRight = helper(grid, startRow + subgridSize / 2, startCol + subgridSize / 2, subgridSize / 2);
    return curr;
  }
  Node *construct(vector<vector<int>> &grid) {
    return helper(grid, 0, 0, grid.size());
  }
};
// @lc code=end
