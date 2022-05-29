#include <algorithm>
#include <iostream>

int mincost(int arr [], int n)
{
    if (n == 1)
    {
        return arr[0];
    }

    if (n == 2)
    {
        return (arr[0] + arr[1]);
    }

    // you can move either one or two adjacent
    int res = arr[n - 1];
    return std::min(mincost(arr, n - 1) + res, mincost(arr, n - 2) + res);
}

int main() 
{
    const int TEST_ARR_SIZE = 6;
    int TEST_ARR [TEST_ARR_SIZE] = { 0, 3, 80, 6, 57, 10 };

    int res = mincost(TEST_ARR, TEST_ARR_SIZE);
    std::cout << res;
}
