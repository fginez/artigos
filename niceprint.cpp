#include <iostream>
#include <array>

int main(int argc, char* argv[])
{
    std::array<int, 10> numbers;
    numbers.fill(0);
    auto it = std::begin(numbers);
    for(auto &i:numbers) {
        std::cout << i << " \n"[++it==numbers.end()];
    }

    return 0;
}
