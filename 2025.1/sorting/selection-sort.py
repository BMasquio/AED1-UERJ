import sys

def selection_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr

def main():
    t = int(input())
    
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split(' ')))
        
        sorted_arr = selection_sort(arr)
        print(' '.join(map(str, sorted_arr)))

if __name__ == "__main__":
    main()
