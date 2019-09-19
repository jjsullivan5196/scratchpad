#include "ioprint.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using namespace std::string_literals;
using ioprint::ioprintf;

int main() {
	// To stdout (multibyte)
	ioprintf(std::cout, "This program has {} buzz and {} fizz\n\n"s, 100, 200);

	// To a stringstream (widechar)
	auto str_stream = wstringstream();
	ioprintf(str_stream, L"Lets put a {} here and a {} there.\nHow about {}?\n"s, 14, 2.22, L"another string"s);
	std::wcout << str_stream.str();
}
