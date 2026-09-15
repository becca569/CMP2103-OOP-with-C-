// Given two inter values, the programs finds out if a number is less, equal or greater than the second number
 #include <iostream>


int main()
{
    int a = 0;
    int b = 0;
    std::cout << "Please enter two integers\n";
    std::cin >> a >> b;
    if (a < b) // condition
        // 1st alternative (if condition is true)
        std::cout << a << " is less than " << b << std::endl;

    else if (a > b)
        // 2nd alternative (if condition is false)
        std::cout << a<< " is greater than to " << b << std::endl;
    else if (a == b)
        std::cout << a << " is equal to " << b << std::endl;
    else
        std::cout << "Invalid input\n";
}

// Try
// This program has a bug: it compares a string to an integer. Modify it so that comparisons are performed using integer values ONLY.
