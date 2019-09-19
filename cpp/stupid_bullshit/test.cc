#include <iostream>
#include <string_view>

using namespace std;

template<const string_view& Name>
struct named_instance
{
  static auto GetName() { return Name; }
};

constexpr string_view operator "" _x(const char* str, size_t n) { return string_view(str, n); }

extern auto const str = string_view("hello", 5);

template<char... C>
struct isthisconst {};

int main()
{
  isthisconst<"hello"> test;
}
