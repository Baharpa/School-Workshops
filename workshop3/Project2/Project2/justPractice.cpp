// Pointer Addition
// pointerAddition.cpp

#include <iostream>

int main()
{
    double a[] = { 1.1, 2.2, 3.3, 4.4 , 5.5 };
    int i = 1;
    double* p;

    p = &a[1];
    std::cout << std::hex;
    std::cout << "a[0] is: " << a[0] << " : " << a << std::endl;
    std::cout << "p[0] is: " << p[0] << " : " << &p[0] << std::endl;
    std::cout << *(p + i) << " : " << p + i << std::endl;
    std::cout << p[i] << " : " << &p[i] << std::endl;
}