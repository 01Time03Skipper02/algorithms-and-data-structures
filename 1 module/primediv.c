#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long long x;
    scanf("%lld", &x);
    if (x < 0) x *= -1;
    int arr[(long long)(sqrt((double) x) - 1)];
    int max_prime_div = 0;

    for (int i = 0; i < (long long)(sqrt((double) x) - 1); i++) {
        arr[i] = i + 2;
    }

    for (int i = 0; i < (long long)(sqrt((double) x) - 1); i++) {
        if (arr[i]) {
            for (int j = (arr[i] * arr[i])-2; j < (long long)(sqrt((double) x) - 1); j += arr[i]) {
                arr[j] = 0;
            }
        }
    }

    for (int i = 0; i < (long long)(sqrt((double) x) - 1); i++){
        if (arr[i] && x % arr[i] == 0 && arr[i] > max_prime_div) {
            max_prime_div = arr[i];
            int tmp = x;
            int buf = 1;
            for (int j = 0; j < (long long)(sqrt((double) x) - 1); j++) {
                while (arr[j] && !(tmp % arr[j])) {
                    buf *= arr[j];
                    tmp /= arr[j];
                }
            }
            if ((buf != 1) && ((x / buf) > max_prime_div)) max_prime_div = x / buf;
        }
    }

    if (max_prime_div) printf("%d", max_prime_div);
    else printf("%lld", x);
}