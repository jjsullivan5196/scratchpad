#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits>

template<typename T>
static inline auto min_set(const T n) -> T {
    return ((T)1 << n) - 1;
}

template<typename T>
static inline auto count_bits(T n) -> T {
    T count = 0;
    while(n) {
        n &= n-1;
        count++;
    }
    return count;
}

template<typename T>
static inline auto count_inv(const T n) -> T {
    auto set = count_bits(n);
    if(n == 0 || n <= min_set(set) || n >= std::numeric_limits<T>::max())
        return 0;
    
    T count = 0;
    for(T i = 0, place = 0; i < set; i++, place++) {
        while(!(n & (1 << place))) place++;
        count += place - i;
    }
    return count;
}

template<typename T>
static inline auto invl(T n, std::string s) -> T {
    std::reverse(s.begin(), s.end());
    for(char& c : s) {
        if(c == '?') {
            c = (n & 1) ? '1' : '0';
            n >>= 1;
        }
    }
    std::reverse(s.begin(), s.end());
    return std::strtol(s.c_str(), nullptr, 2);
}
