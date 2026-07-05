class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        lProd = [1] * n
        rProd = [1] * n

        for i in range(1,n):
            lProd[i] = lProd[i-1] * nums[i-1]

        for i in range(n-2,-1,-1):
            rProd[i] = rProd[i+1] * nums[i+1]


        res = []
        for i in range(n):
            res.append(lProd[i] * rProd[i])

        return res
