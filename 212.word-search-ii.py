#
# @lc app=leetcode id=212 lang=python3
#
# [212] Word Search II
#

# @lc code=start
class Solution:
    def __init__(self):
        self.trie = {}

    def add(self, word):
        curr = self.trie
        for c in word:
            if c not in curr:
                curr[c] = {}
            curr = curr[c]
        curr['$'] = word

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        # trie + backtracking
        # since we need to backtrack, it may be good to store a pointer to the
        # parent or track the path
        for w in words:
            self.add(w)

        possibleWords = []
        rows, cols = len(board), len(board[0])
        visited = [[False] * cols for _ in range(rows)]
        dirs = [[-1, 0], [1, 0], [0, 1], [0, -1]]
        def dfs(cell, currTrie):
            # if this cell has been visited, return
            row, col = cell
            if visited[row][col]:
                visited[row][col] = False
                return
            
            if board[row][col] not in currTrie:
                visited[row][col] = False
                return

            currTrie = currTrie[board[row][col]]            
            visited[row][col] = True            

            # if reached $, this word is possible.
            if '$' in currTrie:
                possibleWords.append(currTrie.pop('$', None))

            # search four directions. add to path if it has not been visited
            for r, c in dirs:
                newRow = row + r
                newCol = col + c
                if (0 <= newRow < rows and 
                    0 <= newCol < cols and 
                    not visited[newRow][newCol] and 
                    board[newRow][newCol] in currTrie):
                    dfs((newRow, newCol), currTrie)
            visited[row][col] = False

        for i in range(rows):
            for j in range(cols):
                dfs((i, j), self.trie)
        return possibleWords


# @lc code=end

