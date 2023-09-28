

def longest_increasing_subsequence(data):
    dp = [1] * len(data)
    dp[len(data)-1] = 1
    for i in range(len(data) -1, -1, -1):
        for j in range(i+1, len(data)):
            if data[i] < data[j]:
                dp[i] = max(dp[i], 1+dp[j])
    
    return max(dp)

def main():
    input_data = list(map(int, input().split()))
    print(longest_increasing_subsequence(input_data))

if __name__ == "__main__":
    main()