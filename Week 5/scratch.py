def mystery_algo(arr, p):
    n = len(arr)
    i = 1
    j = n

    while i < j:
        while (i < j) and (arr[i-1] < p):
            i += 1
        while (i < j) and (arr[j-1] >= p):
            j -= 1
        
        if i < j:
            arr[j-1], arr[i-1] = arr[i-1], arr[j-1]

    return arr

def main():
    input_arr = [26, -2, 3, -1, 0, 4, 88]
    new_arr = mystery_algo(input_arr, 3)
    print(new_arr)

if __name__ == "__main__":
    main()