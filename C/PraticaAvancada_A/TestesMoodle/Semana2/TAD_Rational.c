#include <stdio.h>
#include <stdlib.h>

struct fracao
{
    int numerator;
    int denominator;
};
typedef struct fracao fracao;

fracao* criarFracao(int, int);
fracao* sum(fracao *f1, fracao *f2);
fracao* sub(fracao *f1, fracao *f2);
fracao* divide(fracao *f1, fracao *f2);
fracao* mult(fracao *f1, fracao *f2);
void simplify(fracao *);

int main()
{
    int n_Cases; 
    int N1, N2, D1, D2;
    char op;

    scanf("%d", &n_Cases);


    for (int i = 0; i < n_Cases; i++)
    {
        scanf("%d / %d %c %d / %d", &N1, &D1, &op, &N2, &D2);

        fracao *f1 = criarFracao(N1, D1);
        fracao *f2 = criarFracao(N2, D2);

        fracao *result;
        if (op == '+')
        {
            result = sum(f1,f2);
        }
        if (op == '-')
        {
            result = sub(f1,f2);
        }
        if (op == '*')
        {
            result = mult(f1,f2);
        }
        if (op == '/')
        {
            result = divide(f1, f2);
        }
        printf("%d/%d = ", result->numerator, result->denominator);
        simplify(result);
        printf("%d/%d\n", result->numerator, result->denominator);

        free(f1);
        free(f2);
        free(result);

    }
    return 0;
}

fracao* criarFracao(int num, int den)
{
    fracao *f = (fracao *)malloc(sizeof(fracao));
    f->numerator = num;
    f->denominator = den;
    return f;
}

fracao* sum(fracao *f1, fracao *f2)
{
    /*Sum: (N1*D2 + N2*D1) / (D1*D2)*/
    int num = (f1->numerator * f2->denominator) 
                + (f2->numerator * f1->denominator);
    int den = (f1->denominator * f2->denominator);

    fracao *result = criarFracao(num, den);
    return result;
}

fracao* sub(fracao *f1, fracao *f2)
{
    /*Subtraction: (N1*D2 - N2*D1) / (D1*D2)*/
    int num = (f1->numerator * f2->denominator) 
                - (f2->numerator * f1->denominator);
    int den = (f1->denominator * f2->denominator);

    fracao *result = criarFracao(num, den);
    return result;
}

fracao* mult(fracao *f1, fracao *f2)
{
    /*Multiplication: (N1*N2) / (D1*D2)*/
    int num = f1->numerator * f2->numerator;
    int den = f1->denominator * f2->denominator;

    fracao *result = criarFracao(num, den);
    return result;
}

fracao* divide(fracao *f1, fracao *f2)
{
    /*(N1*D2)/(N2*D1)*/
    int num = f1->numerator * f2->denominator;
    int den = f2->numerator * f1->denominator;

    fracao *result = criarFracao(num, den);
    return result;
}

int _gcd(int a, int b)
{
    if (b == 0)
        return a;
    return _gcd(b, a % b);
}

void simplify(fracao *f)
{
    int gcd = _gcd(f->numerator, f->denominator);
    f->numerator = (f->numerator )/gcd;
    f->denominator = (f->denominator )/gcd;

    if (f->denominator < 0)
    {
        f->denominator = -f->denominator;
        f->numerator = -f->numerator;
    }
}

