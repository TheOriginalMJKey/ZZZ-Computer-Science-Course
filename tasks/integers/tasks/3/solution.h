#include <stdio.h>

const int TEN = 10;
const int ZERO = 0;

int MaxSum(int num) {
    int maxSum = ZERO;
    int currentSum = ZERO;

    int firstDigit = num % TEN;
    num /= TEN;
    int secondDigit = num % TEN;
    num /= TEN;

    while (num > ZERO) {
        int thirdDigit = num % TEN;

        currentSum = firstDigit + secondDigit + thirdDigit;
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }

        firstDigit = secondDigit;
        secondDigit = thirdDigit;
        num /= TEN;
    }

    return maxSum;
}

int Task() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int maxSum = MaxSum(num);
    printf("Maximum sum of triplets: %d\n", maxSum);

    return 0;
}
