from collections import deque
def get_maximum_value_in_window(arr, n, k):
    max_ans = []
    window = deque()

    for i in range(k):
        while window and arr[i] >= arr[window[-1]]:
            window.pop()
        
        window.append(i)
    
    max_ans.append(arr[window[0]])

    for i in range(k,n):

        while window and arr[i] >= arr[window[-1]]: 
            window.pop()

        if window and window[0] <= i - k:
            window.popleft()
        
        window.append(i)
        max_ans.append(arr[window[0]])
    
    return max_ans


if __name__ == "__main__":
    values = list(map(int, input().split()))
    print(values)
    k = int(input())
    print(get_maximum_value_in_window(values, len(values), k))
