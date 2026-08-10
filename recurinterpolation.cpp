#include <stdio.h>

int interpolationSearchRecursive(int arr[], int low, int high, int x) {
    if (low > high || x < arr[low] || x > arr[high])
        return -1;

    if (low == high) {
        if (arr[low] == x) return low;
        return -1;
    }

    int pos = low + (((double)(x - arr[low]) / (arr[high] - arr[low])) * (high - low));

    if (arr[pos] == x)
        return pos;
    else if (x < arr[pos])
        return interpolationSearchRecursive(arr, low, pos - 1, x);
    else
        return interpolationSearchRecursive(arr, pos + 1, high, x);
}

int main() {
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &x);

    int result = interpolationSearchRecursive(arr, 0, n - 1, x);

    if (result != -1)
        printf("%d element is found at index %d\n", x, result);
    else
        printf("%d element is not found\n", x);

    return 0;
}
