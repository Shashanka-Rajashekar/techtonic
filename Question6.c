#include <stdio.h>

int main() {
    int sum = 0, odd_sum = 0, even_sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
        if (i % 2 == 0) {
            even_sum += i;
        } else {
            odd_sum += i;
        }
    }
    printf("Sum of numbers from 1 to 100: %d\n", sum);
    printf("Sum of even numbers from 1 to 100: %d\n", even_sum);
    printf("Sum of odd numbers from 1 to 100: %d\n", odd_sum);
    return 0;
}
