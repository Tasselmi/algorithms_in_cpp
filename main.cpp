#include <iostream>
#include <string>

inline long threeToLong(std::string s)
{
    long answer = s.at(0);
    answer = (answer << 8) + s.at(1);

}

//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}
