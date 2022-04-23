#include <iomanip>
#include <iostream>

int main()
{
    const float CLUB_DISCOUNT_RATE = .1;
    float item1_price, item2_price, tax_rate;
    char has_club_card;

    std::cout << "Enter price of first item: ";
    std::cin >> item1_price;

    std::cout << "Enter price of second item: ";
    std::cin >> item2_price;

    std::cout << "Does customer have a club card? (Y/N): ";
    std::cin >> has_club_card;

    std::cout << "Enter tax rate, e.g. 5.5 for 5.5\% tax: ";
    std::cin >> tax_rate;
    tax_rate = tax_rate / 100;

    float base_price = item1_price + item2_price;

    // apply buy one half off promotion-- lower price item is half price
    /**
     * There are three possible conditions:
     * 1. item1 is cheaper than item2
     * 2. item2 is cheaper than item1
     * 3. item1 and item2 are the same price
     * In the last case, it doesn't matter which item price is halved
     */

    if (item1_price < item2_price)
    {
        item1_price = item1_price / 2;
    }
    else
    {
        item2_price = item2_price / 2;
    }

    float price_after_discount = item1_price + item2_price;

    if (has_club_card == 'y' || has_club_card == 'Y')
    {
        price_after_discount = price_after_discount * (1 - CLUB_DISCOUNT_RATE);
    }

    float final_price = price_after_discount * (1 + tax_rate);

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Base price: " << base_price << "\n";
    std::cout << "Price after discounts: " << price_after_discount << "\n";

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Total price " << final_price;

    return 0;
}
