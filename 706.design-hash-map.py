#
# @lc app=leetcode id=706 lang=python3
#
# [706] Design HashMap
#

# @lc code=start
class MyHashMap:

    def __init__(self):
        self.hashset = [-1] * (10 ** 6 + 1)

    def put(self, key: int, value: int) -> None:
        self.hashset[key] = value

    def get(self, key: int) -> int:
        return self.hashset[key]

    def remove(self, key: int) -> None:
        self.hashset[key] = -1


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
# @lc code=end

