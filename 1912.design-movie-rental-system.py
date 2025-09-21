#
# @lc app=leetcode id=1912 lang=python3
#
# [1912] Design Movie Rental System
#

# @lc code=start
class MovieRentingSystem:

    def __init__(self, n: int, entries: List[List[int]]):
        # rented movie -> priority queue of (price, shop)
        # unrented movie -> priority queue of (price, shop)
        # O(1) for all ops
        # to rent: mark a movie as rented, and add it to the rented queue (if it's already in the queue, just unmark it)
        # to drop: mark a movie as unrented, and add it to the unrented queue (if it's already in the queue, just unmark it)
        # search worst case: all movies has been rented, this can only happen with corresponding numbers of calls to
        # rent, so the amortized runtime should be O(1)
        # we need two heaps, one min-heap with the 5 cheapest. If we rented from the 5 min heap, pop it 
        # and fill it from the other heap. So for search, we return directly the 
        # first heap.

    def search(self, movie: int) -> List[int]:
        # return the cheap 5 min heap
        

    def rent(self, shop: int, movie: int) -> None:
        # if movie is in 5 min heap, remove it from the min heap
        # fill the 5 min heap using items from the larger heap
        # otherwise, mark the item in the heap as rented (we need pointers to each item)
        # in the heap, using shop, movie as key

    def drop(self, shop: int, movie: int) -> None:
        # same logic as rent
        

    def report(self) -> List[List[int]]:
        # rented heap should be simpler and there is no movie -> priority queue


# Your MovieRentingSystem object will be instantiated and called as such:
# obj = MovieRentingSystem(n, entries)
# param_1 = obj.search(movie)
# obj.rent(shop,movie)
# obj.drop(shop,movie)
# param_4 = obj.report()
# @lc code=end

