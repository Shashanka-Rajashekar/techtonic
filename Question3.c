#include <stdio.h>

int majorityElement(int *arr, int n) {
    int count = 1;
    int majority = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] == majority)
            count++;
        else
            count--;
        if (count == 0) {
            majority = arr[i];
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == majority)
            count++;
    }
    if (count > n / 2)
        return majority;
    else
        return -1;
}

int main() {
    int arr[] = {3, 1, 3, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = majorityElement(arr, n);
    if (result == -1)
        printf("No majority element found.");
    else
        printf("The majority element is %d.", result);
    return 0;
}