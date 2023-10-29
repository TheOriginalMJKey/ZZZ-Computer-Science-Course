#include <stdio.h>

const int TEN = 10;
const int ZERO = 0;

int MaxSum(int num) {
    int max_sum = ZERO;
    int current_sum = ZERO;

    int first_digit = num % TEN;
    num /= TEN;
    int second_digit = num % TEN;
    num /= TEN;

    while (num > ZERO) {
        int third_digit = num % TEN;

        current_sum = first_digit + second_digit + third_digit;
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }

        first_digit = second_digit;
        second_digit = third_digit;
        num /= TEN;
    }

    return max_sum;
}

int Task() {
    int num = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    int max_sum = MaxSum(num);
    printf("Maximum sum of triplets: %d\n", max_sum);

    return 0;
}
