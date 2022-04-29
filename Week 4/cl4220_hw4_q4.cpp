#include <cmath>
#include <iostream>

int main()
{
    int num, seq_len, product;
    float geo_mean;

    // Section A (for loop)
    std::cout << "Section A\n";

    std::cout << "Please enter the length of the sequence: ";
    std::cin >> seq_len;

    std::cout << "Please enter your sequence:\n";

    product = 1;
    for (int i = 0; i < seq_len; i++)
    {
        int num;
        std::cin >> num;
        product *= num;
    }

    geo_mean = std::pow(product, 1.0 / seq_len); // use a float here as we don't want integer div
    std::cout << "The geometric mean is: " << geo_mean << '\n';

    // Section B (while loop)
    std::cout << "\nSection B\n";
    std::cout << "Please enter a non-empty sequence of positive integers, "
              << "each one in a separate line. End your sequence by typing -1:\n";

    seq_len = 0;
    product = 1;
    while (true)
    {
        std::cin >> num;
        if (num == -1)
        {
            break;
        }
        product *= num;
        seq_len += 1;
    }
    
    geo_mean = std::pow(product, 1.0 / seq_len);
    std::cout << "The geometric mean is: " << geo_mean;

    return 0;
}
