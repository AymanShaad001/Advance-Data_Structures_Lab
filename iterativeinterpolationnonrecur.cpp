#include <stdio.h>

int interpolationSearchIterative(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }

        int pos = low + (((double)(x - arr[low]) / (arr[high] - arr[low])) * (high - low));

        if (arr[pos] == x)
            return pos;

        if (x < arr[pos])
            high = pos - 1;
        else
            low = pos + 1;
    }

    return -1;
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

    int result = interpolationSearchIterative(arr, n, x);

    if (result != -1)
        printf("%d element is found at index %d\n", x, result);
    else
        printf("%d element is not found\n", x);

    return 0;
}
