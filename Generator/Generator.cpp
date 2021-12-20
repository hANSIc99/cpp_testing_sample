#include "Generator.h"
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>

std::stringstream &Generator::generate(std::stringstream &stream, const int range) {
    std::vector<int> data(range);
    std::iota(data.begin(), data.end(), 1);

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(data.begin(), data.end(), g);

    for (const auto n : data) {

        stream << std::to_string(n) << " ";
    }

    return stream;
}