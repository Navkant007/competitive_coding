
def main():
    str1 = input()
    str2 = input()
    ans_str = ""
    ans_len = float('inf')
    index_s1, index_s2 = 0, 0
    while(index_s1 < len(str1)):
        if str1[index_s1] == str2[index_s2]:
            index_s2 += 1
            if index_s2 == len(str2):
                start, end = index_s1, index_s1+1
                index_s2 -= 1
                while(index_s2 >= 0):
                    if str1[start] == str2[index_s2]:
                        index_s2 -= 1
                    start -= 1
                
                start += 1
                if (end - start) < ans_len:
                    ans_len = end - start
                    ans_str = str1[start:end]
                
                index_s1 = start
                index_s2 = 0

        index_s1 += 1

    print(ans_str)
    

if __name__ == "__main__":
    main()