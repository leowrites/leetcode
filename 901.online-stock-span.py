#
# @lc app=leetcode id=901 lang=python3
#
# [901] Online Stock Span
#

# @lc code=start
class StockSpanner:

    def __init__(self):
        self.accumulation = []
        self.prices = []

    def next(self, price: int) -> int:
        count = 1
        while self.prices and self.prices[-1] <= price:
            self.prices.pop()
            acc = self.accumulation.pop()
            count += acc
        self.accumulation.append(count)
        self.prices.append(price)
        return count
        


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
# @lc code=end

