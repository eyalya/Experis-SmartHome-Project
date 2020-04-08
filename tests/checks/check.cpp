#include <iostream>


int main()
{
    char c = 'c';
    char* ptr = &c;
    size_t a = reinterpret_cast<size_t>(ptr);

    std::cout << "a is " << a << std::endl;
    std::cout << "ptr addr is " << &ptr << std::endl;
    return 0;
}
