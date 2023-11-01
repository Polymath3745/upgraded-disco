#include <iostream>

int Max(int x, int y)
{
    int max{0};
    if (x > y)
    {
        max = x;
    }
    else if (y > x)
    {
        max = y;
    }
    else
    {
        max = x;
    }
    return max;
}