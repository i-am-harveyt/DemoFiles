def BinarySearch(arr, key, left, right):
    while left <= right:
        mid = left + (right - left) // 2
        if arr[mid] == key:
            return mid
        elif arr[mid] < key:
            left = mid + 1
        elif arr[mid] > key:
            right = mid - 1
    return -1

arr = [1, 3, 5, 7, 9, 11, 13, 16, 25]
pos = BinarySearch(arr, 7, 0, len(arr) - 1)
print("7 is the", pos, "th element in the list.\n")