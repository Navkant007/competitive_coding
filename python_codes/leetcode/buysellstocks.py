
def maxProfit(stocks):
    l = 0
    max_profit = 0
    for r in range(1, len(stocks)):
        if stocks[l] < stocks[r]:
            profit = stocks[r] - stocks[l]
            max_profit = max(max_profit, profit)
        else:
            l = r
    return max_profit


def main():
    stocks = list(map(int, input().split()))
    print(maxProfit(stocks))


if __name__ == "__main__":
    main()