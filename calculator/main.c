#include <stdio.h>
#include <float.h>

int main()
{
    char op;
    double augend, addend, sum;

    puts("AUGEND OP ADDEND");
    scanf("%lf %c %lf", &augend, &op, &addend);

    switch (op)
    {
        case '+':
            sum = augend + addend;
            break;
        case '-':
            sum = augend - addend;
            break;
        case '*':
            sum = augend * addend;
            break;
        case '/':
            sum = augend / addend;
            break;
        case '%':
            sum = (float)((int)(augend + 0.5) % (int)(addend + 0.5));
            break;
        // case '//':
        default:
            sum = -DBL_MAX;
    }

    if (sum != -DBL_MAX)
    {
        printf("%.2lf", sum);
    } else
    {
        printf("ERROR");
    }

    return 0;
}