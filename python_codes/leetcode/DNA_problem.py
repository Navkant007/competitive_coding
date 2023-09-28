# def find_repeated_sequences(s, k):
#     # your code will replace this placeholder return statement
#     ans = list()
#     ans_set = set()
#     for i in range(len(s)-k+1):
#         if s[i:i+k] in ans:
#             ans_set.add(s[i:i+k])
#         else:
#             ans.append(s[i:i+k])
#     print(ans_set)
#     print(ans)
#     return ans_set


# if __name__ == "__main__":
#     s = input()
#     k = int(input())
#     find_repeated_sequences(s, k)


def find_repeated_sequences(s, k):
    window_size = k
    if len(s) <= window_size:
        return set()

    # parameters of rolling hash
    base = 4        # 'a', the hash parameter
    hi_place_value = pow(base, window_size - 1) # a^(k-1), the highest place value

    # mapping of a character into an integer
    mapping = {'A': 1, 'C': 2, 'G': 3, 'T': 4}
    numbers = []
    for i in range(len(s)):
        numbers.append(mapping.get(s[i]))

    hashing = 0
    substring_hashes, output = set(), set()
    # iterate over all window-sized substrings
    for start in range(len(s) - window_size + 1):
        # hash function of current subsequence
        if start != 0:
            hashing = (hashing - numbers[start - 1] * hi_place_value) * base \
                    + numbers[start + window_size - 1]
        else:
            for end in range(window_size):
                hashing = hashing * base + numbers[end]
        # subsequence and output sets
        if hashing in substring_hashes:
            output.add(s[start:start + window_size])
        substring_hashes.add(hashing)
    return output


def main():
    inputs_string = ["ACGT", "AGACCTAGAC", "AAAAACCCCCAAAAACCCCCC", "GGGGGGGGGGGGGGGGGGGGGGGGG",
                     "TTTTTCCCCCCCTTTTTTCCCCCCCTTTTTTT", "TTTTTGGGTTTTCCA",
                     "AAAAAACCCCCCCAAAAAAAACCCCCCCTG", "ATATATATATATATAT"]
    inputs_k = [3, 3, 8, 12, 10, 14, 10, 6]

    for i in range(len(inputs_k)):
        print(i+1, ".\tInput Sequence: \'", inputs_string[i], "\'", sep="")
        print("\tk: ", inputs_k[i], sep="")
        print("\tRepeated Subsequence: ",
              find_repeated_sequences(inputs_string[i], inputs_k[i]))
        print("-"*100)


if __name__ == '__main__':
    main()
