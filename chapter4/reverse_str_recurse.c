#include <stdio.h>

int reverse(char s[], int i);
void itoa(int n, char s[]);
int itoa_recurse(int n, char s[]);

int main()
{

    char s[] = "laplace";
    reverse(s, 0);
    printf("%s \n", s);

    char itoa_array[100];
    //itoa(4356, itoa_array);

    char itoa_array_rec[100];
    int pos = itoa_recurse(-4356, itoa_array_rec);
    itoa_array_rec[pos] = '\0';

    printf("res=%s\n", itoa_array_rec);
}

int reverse(char s[], int i)
{

    char c = s[i];
    if (c == '\0')
    {
        return 0;
    }
    else
    {
        int p = reverse(s, i + 1);
        s[p] = c;
        return p + 1;
    }
}

void itoa(int n, char s[])
{

    int r;
    int i = 0;

    do
    {
        r = n % 10;
        s[i++] = '0' + r;
    } while ((n /= 10) != 0);

    s[i] = '\0';

    reverse(s, 0);

    printf("result itoa: %s\n", s);
}

int itoa_recurse(int n, char s[])
{

    //only on first call
    if (n < 0)
    {
        n = -n;
        s[0] = '-';
    }

    int r = n % 10;
    int q = n / 10;

    if (q == 0)
    {
        int start_pos = 0;
        if (s[start_pos] == '-')
        {
            start_pos = 1;
        }
        s[start_pos] = '0' + r;
        return start_pos + 1;
    }
    else
    {
        int pos = itoa_recurse(q, s);
        s[pos] = '0' + r;
        return pos + 1;
    }
}
