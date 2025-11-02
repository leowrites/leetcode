#
# @lc app=leetcode id=721 lang=python3
#
# [721] Accounts Merge
#

# @lc code=start
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        parent = [i for i in range(len(accounts))]
        accountNames = [account[0] for account in accounts]
        # the email just need to be an entry into the set
        emailToOwner = {}

        def find(i):
            if parent[i] == i:
                return i
            parent[i] = find(parent[i])
            return parent[i]
        
        def union(i, j):
            root_i = find(i)
            root_j = find(j)
            if root_i == root_j:
                return
            # perform rank later
            parent[root_i] = root_j
        
        for i, account in enumerate(accounts):
            for j in range(1, len(account)):
                # find existing emailToOwner if there is one, if not 
                # add it to the dictionary
                email = account[j]
                # first time the email is seen, continue
                if email not in emailToOwner:
                    emailToOwner[email] = i
                    continue
                p = find(emailToOwner[email])
                if p == i:
                    continue
                # union the two accounts
                union(i, p)
        # for each email, use find to find the owner, construct the email
        res = collections.defaultdict(list)
        for email, p in emailToOwner.items():
            res[find(p)].append(email)
        r = []
        for o, emails in res.items():
            r.append([accountNames[o]] + sorted(emails))
        return r
        
# @lc code=end

