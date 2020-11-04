#include <iostream>
#include <string>
#include <vector>

inline long threeToLong(std::string s)
{


    long answer = s.at(0);
    answer = (answer << 8) + s.at(1);
    return answer;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    //64位处理器、64位的操作系统
    std::vector<unsigned int> price = {10, 10, 15, 20, 30};
    std::vector<long> discount = {-800, -750, -800, -900, -700};
    std::vector<unsigned long> quantity = {996, 965, 666, 120, 110};
    std::vector<long long> output;

    int n = 5;
    for (int i = 0; i <= n; ++i)
    {
        output[i] = price[i] * quantity[i] - discount[i];
        std::cout << output[i] << ", ";
    }

    return 0;
}
