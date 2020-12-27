#ifndef LEVENSHTEIN_DISTANCE_HPP
#define LEVENSHTEIN_DISTANCE_HPP

#include <algorithm>
#include <vector>

constexpr size_t MaxLevenshteinDistance = 3;
constexpr double coefOfLength = 0.2;

template<typename T>
class LevenshteinDistance {
public:
    LevenshteinDistance() = default;

    ~LevenshteinDistance() = default;

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

    const size_t min_size = source.size(), max_size = target.size();
    std::vector<size_t> lev_dist(min_size + 1);

    for (size_t i = 0; i <= min_size; ++i) {
        lev_dist[i] = i;
    }

    for (size_t j = 1; j <= max_size; ++j) {
        size_t previous_diagonal = lev_dist[0], previous_diagonal_save;
        ++lev_dist[0];

        for (size_t i = 1; i <= min_size; ++i) {
            previous_diagonal_save = lev_dist[i];
            if (source[i - 1] == target[j - 1]) {
                lev_dist[i] = previous_diagonal;
            } else {
                lev_dist[i] = std::min(std::min(lev_dist[i - 1], lev_dist[i]), previous_diagonal) + 1;
            }
            previous_diagonal = previous_diagonal_save;
        }
    }

    return lev_dist[min_size];
}

#endif //LEVENSHTEIN_DISTANCE_HPP