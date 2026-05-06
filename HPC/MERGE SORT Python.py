from concurrent.futures import ThreadPoolExecutor

# User Input
arr = list(map(int, input("Enter elements: ").split()))

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

# Parallel Merge Sort
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

# Sorting
sorted_arr = merge_sort(arr)

# Output
print("Parallel Merge Sort:", sorted_arr)