#include <cstdio>
#include <cstdint>
#include <tuple>
#include <utility>

/*
template<typename... Args>
struct doesthiswork {
	union data_t {
		data_t() { std::printf("Union constructor"); }
		std::tuple<Args&...> structure;
		//uint8_t data[sizeof(std::tuple<Args&...>)];
	};

	doesthiswork(Args&... args) {
		std::printf("Saver constructor");
		data.structure = std::tuple<Args&...>(args...);
	}

	void write(const char* fname) {
		auto file = std::fopen(fname, "w");
		std::fwrite(data.data, sizeof(uint8_t), sizeof(data), file);
		fclose(file);
	}

	void read(const char* fname) {
		auto file = std::fopen(fname, "w");
		std::fread(data.data, sizeof(uint8_t), sizeof(data), file);
		fclose(file);
	}

	private:
	data_t data;
};
*/

template<typename... Args>
union data_t {
	data_t(Args&... args) { structure = std::tuple<Args&...>(args...); }
	std::tuple<Args&...> structure;
	//uint8_t data[sizeof(std::tuple<Args&...>)];
};

struct dat {
	/*
	auto create_saver() {
		return doesthiswork(fp, num, letter);
	}
	*/

	float fp;
	int num;
	char letter;
};

int main() {
	auto test = dat();
	//auto data = std::tuple<float&, int&, char&>(test.fp, test.num, test.letter);
	auto data = data_t(test.fp, test.num, test.letter);

	/*
	test.fp = 32.125;
	test.num = 56;
	test.letter = 'Z';

	std::printf("%f, %d, %c\n", test.fp, test.num, test.letter);
	saver.write("test.dat");

	test.fp = 12.5;
	test.num = 10;
	test.letter = 'C';

	saver.read("test.dat");
	std::printf("%f, %d, %c\n", test.fp, test.num, test.letter);
	*/
}
