
def sort(arr, l, r):
    if l < r:
        middle = (l + r) // 2
        sort(arr, l, middle)
        sort(arr, middle + 1, r)
        merge(arr, l, middle, r)


def merge(arr, l, m, r):
    # merge two arrygs of arr
    # first is arr[l..m]
    # second is arr[m + 1..r]
    n1 = m - l + 1
    n2 = r - m
    # create temp arrays
    L = [0] * (n1)
    R = [0] * (n2)
    # copy data to temp arrays L and R
    for i in range(0, n1):
        L[i] = arr[l + i]

    for j in range(0, n2):
        R[j] = arr[m + 1 + j]

    # merge the temp arrays back into array[l..r]
    i = 0
    j = 0
    k = l
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    # copy the remaining elements of L, if there are any
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    # copy the remaining elements of R if there are any
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1


def merge_sort(arr):
    size = len(arr)
    sort(arr, 0, size - 1)


def main():
    arr = [5, 2, 4, 7, 8, 2, 7, 2, 6, 2, 3, 4]
    print('original', arr)
    merge_sort(arr)
    print('sorted', arr)


if __name__ == '__main__':
    main()
