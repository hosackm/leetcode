#include <stdio.h>
#include <limits.h>

#define NUMCASES (5)

int atoi(const char *str)
{
    int         result   = 0;
    int         negative = 0;
    const char *p_ch     = str;

    if(!p_ch) // null string passed in
    {
        return 0;
    }

    // ignore leading whitespace ' '
    if(*p_ch == ' ')
    {
        for(; *p_ch == ' '; p_ch++){}
    }

    // parse optional '-'/'+'
    if(*p_ch == '+' || *p_ch == '-')
    {
        negative = *p_ch == '-' ? 1 : 0;
        p_ch++;
    }

    while(*p_ch != '\0')
    {
        int digit;

        switch(*p_ch)
        {
            case '0': digit = 0; break;
            case '1': digit = 1; break;
            case '2': digit = 2; break;
            case '3': digit = 3; break;
            case '4': digit = 4; break;
            case '5': digit = 5; break;
            case '6': digit = 6; break;
            case '7': digit = 7; break;
            case '8': digit = 8; break;
            case '9': digit = 9; break;
            default: goto done;
        }

        // check if we're going over the integer limit
        if((INT_MAX/10) < result || ((INT_MAX-digit)/10) < result)
        {
            result = negative ? INT_MIN : INT_MAX;
            goto done;
        }

        // shift result by one decimal place and add in this digit
        result *= 10;
        result += digit;

        // move to next character
        p_ch++;
    }

done:
    return negative ? -result : result;
}

int main(int argc, char *argv[])
{
    int i;
    struct testcase
    {
        char *input;
        int output;
    };
    static const struct testcase testcases[NUMCASES] = {
        {"42", 42},
        {"    -42", -42},
        {"4193 with words", 4193},
        {"words and 987", 0},
        {"-91283472332", INT_MIN}
    };

    for(i = 0; i < NUMCASES; i++)
    {
        struct testcase c = testcases[i];
        int result = atoi(c.input);
        if(result != c.output)
        {
            fprintf(stderr, "Failed: case '%s' -> %d, got: %d\n", c.input, c.output, result);
        }
    }

    return 0;
}
