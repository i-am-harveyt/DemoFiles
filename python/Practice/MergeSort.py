def mergeSort(arr, left, right, leftB, rightB):
    if leftB< rightB:   
        mergeSort(arr, left, right, leftB, leftB + (rightB - leftB) // 2)
        mergeSort(arr, left, right, leftB + (rightB - leftB) // 2 + 1, rightB)
        merge(arr, left, right, leftB, leftB + (rightB - leftB) // 2, rightB)

def merge(arr, left, right, leftB, mid, rightB):
    lenT1 = mid - leftB + 1
    lenT2 = rightB - (mid + 1) + 1

    for index in range(lenT1):
        left[index] = arr[leftB + index]
    for index in range(lenT2):
        right[index] = arr[mid + 1 + index]

    cur1 = 0
    cur2 = 0
    current = leftB
    while cur1 < lenT1 and cur2 < lenT2 :
        if left[cur1] <= right[cur2]:
            arr[current] = left[cur1]
            cur1 += 1
        else:
            arr[current] = right[cur2]
            cur2 += 1
        
        current += 1
    
    while cur1 < lenT1:
        arr[current] = left[cur1]
        current += 1
        cur1 += 1
    
    while cur2 < lenT2:
        arr[current] = right[cur2]
        current += 1
        cur2 += 1

string = input("Input a line of number divided by space(n <= 100):")
splitted = string.split(' ')
arr = [int(elements) for elements in splitted]
leftB = 0
rightB = len(arr)
left = [0 for elements in range(100)]
right = [0 for elements in range(100)]
mergeSort(arr, left, right, leftB, rightB - 1)
print(arr)
print("\n")