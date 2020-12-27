#ifndef LEVENSHTEIN_DISTANCE_HPP
#define LEVENSHTEIN_DISTANCE_HPP

#include <algorithm>
#include <vector>

constexpr size_t MaxLevenshteinDistance = 3;
constexpr double coefOfLength = 0.2;

template<typename T>
class LevenshteinDistance {
public:
    LevenshteinDistance() = delete;

    ~LevenshteinDistance() = delete;

    LevenshteinDistance(const LevenshteinDistance &rhs) = delete;

    LevenshteinDistance &operator=(const LevenshteinDistance &rhs) = delete;

    static size_t calculate(const T &source,
                            const T &target);
};

template<typename T>
size_t LevenshteinDistance<T>::calculate(const T &source, const T &target) {
    if (source.size() > target.size()) {
        return calculate(target, source);
    }

    const size_t minSize = source.size();
    std::vector<size_t> levDist(minSize + 1);

    for (size_t i = 0; i <= minSize; ++i) {
        levDist[i] = i;
    }

    const size_t maxSize = target.size();
    for (size_t j = 1; j <= maxSize; ++j) {
        size_t previousDiagonal = levDist[0], previousDiagonalSave;
        ++levDist[0];

        for (size_t i = 1; i <= minSize; ++i) {
            previousDiagonalSave = levDist[i];
            if (source[i - 1] == target[j - 1]) {
                levDist[i] = previousDiagonal;
            } else {
                levDist[i] = std::min(std::min(levDist[i - 1], levDist[i]), previousDiagonal) + 1;
            }
            previousDiagonal = previousDiagonalSave;
        }
    }

    return levDist[minSize];
}

#endif //LEVENSHTEIN_DISTANCE_HPP