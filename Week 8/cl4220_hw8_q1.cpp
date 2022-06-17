#include <iostream>

void print_line(int n, char c)
{
    if (n == 1)
    {
        std::cout << c;
    }
    else
    {
        print_line(n - 1, c);
        std::cout << c;
    }
}

void print_triangle(int n)
{
    if (n == 1)
    {
        std::cout << '*' << '\n';
    }
    else
    {
        print_triangle(n - 1);
        print_line(n, '*');
        std::cout << '\n';
    } 
}

void print_inverted_triangle(int n)
{
    if (n == 1)
    {
        std::cout << '*' << '\n';
    }
    else
    {
        print_line(n, '*');
        std::cout << '\n';
        print_inverted_triangle(n - 1);
    }   
}

void print_opposite_triangles(int n)
{
    print_inverted_triangle(n);
    print_triangle(n);
}

void print_ruler(int n)
{
    if (n == 1)
    {
        std::cout << '-' << '\n';
    }
    else
    {
        print_ruler(n - 1);

        print_line(n, '-');
        std::cout << '\n';

        print_ruler(n - 1);
    }
}

int main()
{
    print_ruler(4);
}

/**
 * n = 4
 * 
 * First call of print_ruler
 * 1. we call print_ruler(3)
 * 2. we call print_ruler(2)
 * 3. we call print_ruler(1)
 * 4. we call print_ruler(0) (n is still 1)
 * 5. print_line(1)- prints one dash
 * 6. print a newline
 * 7. we call print_ruler(0) (our one frame ends here)
 * 
 * Second call of print_ruler
 * 1. we are now in the n = 2 frame
 * 2. print two dashes (print_line(2))
 * 3. now we encounter print_ruler(1), which already know prints one dash
 * 
 * Third call of print_ruler
 * 1. we are now in the n = 3 frame
 * 2. now we print three dashes (print_line(3))
 * 3. now we encounter print_ruler(2), which prints 1 dashes, 2 dashes, and 1 dashes
 * 
 * Fourth call of print_ruler
 * 1. we print four dashes (print_line(4))
 * 2. now we encounter print_ruler(3), which we know prints 
 *          1 dashes, 
 *          2 dashes, 
 *          1 dashes, 
 *          3 dashes,
 *          1 dashes,
 *          2 dashes,
 *          1 dashes,
 */
