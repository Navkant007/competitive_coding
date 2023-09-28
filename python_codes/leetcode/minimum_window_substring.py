def find_minimum(s, t):
    ansl = float('inf')
    ans = ""
    for i in range(len(s)):
        for j in range(i+1, len(s)+1):
            ss = s[i:j]
            # print(f"i---->{i}  j----->{j}")
            print(f"this is ss---->{ss}")
            k = 0
            for p in range(len(t)):
                if t[p] in ss:
                    k += 1
            # print(f"this is K -----> {k}")
            if k == len(t):
                if len(ss) < ansl:
                    ans = ss
                    ansl = len(ss)
    
    print(ans)

def call_helper():
    s = input()
    t = input()
    find_minimum(s, t)


if __name__ == "__main__":
    call_helper()



def get_prmutations(string):
    from itertools import permutations
    
    #Taking input
    
    # Converitng into iterable object to pass in the function
    string = list(string)
    permu = permutations(string, len(string))
    
    # Printing all the permutations
    # Using join function to join the string
    
    for i in list(permu):
        print("".join(i))