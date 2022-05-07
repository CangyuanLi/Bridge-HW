#include <iostream>

void print_shifted_triangle(int n, int m, char symbol)
{
    int num_chars = 1;
    int num_spaces = m + (n - 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < num_spaces; j++)
        {
            std::cout << ' ';
        }

        for (int j = 0; j < num_chars; j++)
        {
            std::cout << symbol;
        }

        num_chars += 2;
        num_spaces -= 1;

        std::cout << '\n';
    }
    
}

void print_pine_tree(int n, char symbol)
{
    int margin = n;
    for (int i = 2; i <= n + 1; i++)
    {
        print_shifted_triangle(i, margin, symbol);
        margin -= 1;
    }
}

int main()
{
    int num_triangles;
    std::cout << "Please enter the number of triangles: ";
    std::cin >> num_triangles;

    char symbol;
    std::cout << "Please enter the symbol: ";
    std::cin >> symbol;

    print_pine_tree(num_triangles, symbol);
}