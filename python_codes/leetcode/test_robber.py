



def robberplanning(nums):
    if not nums:
        return 0
    if len(nums) == 2:
        return max(nums[0], nums[1])
    dp = [0] * len(nums)
    dp[0] = nums[0]
    for i in range(2, len(nums)):
        dp[i] = max(nums[i] + dp[i-2], dp[i-1])
    
    return dp[len(nums)-1]

def main():
    nums = list(map(int, input().split()))
    print(robberplanning(nums))

if __name__ == "__main__":
    main()