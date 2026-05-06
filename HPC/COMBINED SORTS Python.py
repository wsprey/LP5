from concurrent.futures import ThreadPoolExecutor

# User Input
arr = list(map(int, input("Enter elements: ").split()))

# -------- Parallel Bubble Sort --------
def bubble_sort(arr):

    n = len(arr)

    for i in range(n):

        for j in range(0, n - i - 1):

            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

    return arr

# -------- Parallel Merge Sort --------
def merge_sort(arr):

    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2

    left = arr[:mid]
    right = arr[mid:]

    with ThreadPoolExecutor() as executor:

        left_future = executor.submit(merge_sort, left)
        right_future = executor.submit(merge_sort, right)

        left = left_future.result()
        right = right_future.result()

    return merge(left, right)

# Merge Function
def merge(left, right):

    result = []

    i = j = 0

    while i < len(left) and j < len(right):

        if left[i] < right[j]:
            result.append(left[i])
            i += 1

        else:
            result.append(right[j])
            j += 1

    result.extend(left[i:])
    result.extend(right[j:])

    return result

# Perform Sorting
bubble_result = bubble_sort(arr.copy())
merge_result = merge_sort(arr.copy())

# Output
print("\nParallel Bubble Sort:", bubble_result)
print("Parallel Merge Sort:", merge_result)