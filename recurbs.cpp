#include <stdio.h>

int binarySearchRecursive(int arr[], int low, int high, int x) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == x)
        return mid;
    else if (x < arr[mid])
        return binarySearchRecursive(arr, low, mid - 1, x);
    else
        return binarySearchRecursive(arr, mid + 1, high, x);
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

    int result = binarySearchRecursive(arr, 0, n - 1, x);

    if (result != -1)
        printf("%d element is found at index %d\n", x, result);
    else
        printf("%d element is not found\n", x);

    return 0;
}
