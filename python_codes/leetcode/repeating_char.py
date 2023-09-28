


def reapeating_char(s):
    if not s:
        return 0
    
    # abcabcbb
    counter_map = {}
    max_len = 0
    corrent_len = 0

    start = 0
    end = 0
    while(end < len(s)):
        
        counter_map[s[end]] = counter_map.get(s[end], 0) + 1
        # print(counter_map)
        
        while(counter_map[s[end]] > 1):
            counter_map[s[start]] -= 1
            start += 1
                # if counter_map[s[start]] == 0:
                #     counter_map.pop(s[start])
        
        if end - start + 1 > max_len:
            max_len = end -start +1
        end += 1
    return max_len

if __name__ == "__main__":
    s = input()
    print(reapeating_char(s))

