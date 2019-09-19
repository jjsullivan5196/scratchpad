#pragma once
#include <cstdint>
#include <string>
#include <limits>
#include <iterator>
using uint = uint32_t;

static inline uint count_bits(const std::string n) {
    uint count = 0;
    for(const char& c : n) {
        if(c == '1') count++;
    }
    return count;
}

static inline uint count_inv(const std::string n) {
    auto set = count_bits(n);
    if(set == 0)
        return 0;
    
    uint count = 0;
    auto begin = n.rbegin(), end = n.rend(), it = begin;
    for(uint i = 0; i < set; i++, it++) {
        while(*it == '0') it++;
        count += std::distance(begin, it) - i;
    }
    return count;
}

template<typename T>
static inline std::string invl(T n, std::string s) {
    for(auto it = s.rbegin(), end = s.rend(); it != end; it++) {
        if(*it == '?') {
            *it = (n & 1) ? '1' : '0';
            n >>= 1;
        }
    }
    return s;
}
