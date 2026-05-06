# User Input
arr = list(map(int, input("Enter elements: ").split()))

# Bubble Sort
def bubble_sort(arr):

    n = len(arr)

    for i in range(n):

        for j in range(0, n - i - 1):

            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

    return arr

# Sorting
sorted_arr = bubble_sort(arr)

# Output
print("Parallel Bubble Sort:", sorted_arr)