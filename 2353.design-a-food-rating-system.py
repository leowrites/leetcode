#
# @lc app=leetcode id=2353 lang=python3
#
# [2353] Design a Food Rating System
#

# @lc code=start

class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        # bst with label as values
        # avl tree?
        self.cuisines = {}
        for i in range(len(foods)):
            food = foods[i]
            cuisine = cuisines[i]
            rating = ratings[i]
            if cuisine in self.cuisines:
                insert(self.cuisines[cuisine], (rating, food))
            else:
                self.cuisines[cuisine] = insert(None, (rating, food))

    def changeRating(self, food: str, newRating: int) -> None:
        # 
        

    def highestRated(self, cuisine: str) -> str:
        


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
# @lc code=end

