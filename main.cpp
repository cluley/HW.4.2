#include <iostream>
#include <fstream>

class Adress {
public:
	void set(std::ifstream& input);
	void get_out(std::ofstream& output);
	std::string get_city() { return city; }
private:
	std::string city;
	std::string strt;
	int bldng;
	int aptmt;
};

void Adress::set(std::ifstream& input) {
	input >> city >> strt >> bldng >> aptmt;
}

void Adress::get_out(std::ofstream& output) {
	output << city << ", " << strt << ", " << bldng << ", " << aptmt << '\n';
}

template <typename T>
void wipe(T& arr) {
	delete[] arr;
	arr = nullptr;
}

int main(int argc, char** argv) {
	int total;
	std::ifstream input("in.txt");
	input >> total;

	Adress* adresses = new Adress[total];

	for (int i = 0; i < total; i++) {
		adresses[i].set(input);
	}

	bool temp;
	do {
		temp = false;
		for (int i = 1; i < total; i++) {
			if (adresses[i - 1].get_city() > adresses[i].get_city()) {
				Adress swap = adresses[i - 1];
				adresses[i - 1] = adresses[i];
				adresses[i] = swap;
				temp = true;
			}
		}
	} while (temp == true);

	std::ofstream output("out.txt");
	output << total << '\n';

	for (int i = 0; i < total; i++) {
		adresses[i].get_out(output);
	}

	wipe(adresses);

	return 0;
}