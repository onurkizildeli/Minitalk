#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <wchar.h>
#include "minitalk.h"

int a;

int test_function(int b)
{
    a = 3;
    b = 4;

    printf("a = %d, b = %d\n", a, b);
}

int main()
{
    //a = 01100001
    int bit = 1;
    int test;
    char c = 'a';
    test = 1 & (c >> 0);
    printf("%d", test);
    test = 1 & (c >> 1);
    printf("%d", test);
    test = 1 & (c >> 2);
    printf("%d", test);
    test = 1 & (c >> 3);
    printf("%d", test);
    test = 1 & (c >> 4);
    printf("%d", test);
    test = 1 & (c >> 5);
    printf("%d", test);
    test = 1 & (c >> 6);
    printf("%d", test);
    test = 1 & (c >> 7);
    printf("%d", test);
    test_function(0);
    return 0;
}