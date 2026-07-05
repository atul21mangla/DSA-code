class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        lSum = 0
        rSum = sum(nums) - nums[0]

        print(rSum)

        for i in range (len(nums)):
            if lSum == rSum:
                return i

            else:
                if i == len(nums)-1 :
                    return -1
                lSum+= nums[i]
                rSum -= nums[i+1]

        return -1
        