#include <stdio.h>
#include <limits.h>
#include <float.h>

/* The meter register is a 16-bit counter: after 65535 it rolls over to 0. */
typedef unsigned short meter_t;

unsigned int consumption(meter_t previous, meter_t current)
{
    /* TODO 1: Unsigned 16-bit wrap-around subtraction without if-else */
    return (meter_t)(current - previous);
}

int main(void)
{
    printf("=== Complete the Code Output ===\n");
    printf("sizeof(meter_t) = %zu bytes, maximum reading = %u\n",
           sizeof(meter_t), (unsigned)USHRT_MAX);
    printf("Consumption: %u units\n", consumption(1200, 1530));
    printf("Consumption: %u units\n", consumption(65400, 120));   /* rolled over */

    printf("\n=== System Type Sizes & Ranges ===\n");
    printf("unsigned short : %zu B (0 .. %u)\n", sizeof(unsigned short), USHRT_MAX);
    printf("int            : %zu B (%d .. %d)\n", sizeof(int), INT_MIN, INT_MAX);
    printf("long           : %zu B (%ld .. %ld)\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("long long      : %zu B (%lld .. %lld)\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
    printf("float          : %zu B (precision = %d digits)\n", sizeof(float), FLT_DIG);
    printf("double         : %zu B (precision = %d digits)\n", sizeof(double), DBL_DIG);

    /* 4,000 bills of Rs 162.55 (16255 paise) */
    float f_total = 0.0f;
    long p_total = 0L;
    for (int i = 0; i < 4000; i++) {
        f_total += 162.55f;
        p_total += 16255L;
    }
    printf("\n=== 4,000 Bills Precision Test (Expected: Rs 650200.00) ===\n");
    printf("float total = Rs %.2f | integer paise total = Rs %ld.%02ld\n",
           f_total, p_total / 100, p_total % 100);
    return 0;
}
