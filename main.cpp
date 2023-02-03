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

void bubble(std::string* arr, int size) {
	bool temp;
	do {
		temp = false;
		for (int i = 0; i < size; i++) {
			if(arr[i] > arr[i + 1]) {
				std::string swap = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = swap;
				temp = true;
			}
		}
	} while(temp == true);
}

template <typename T>
void wipe(T arr) {
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

	std::string* arr = new std::string[total];

	for (int i = 0; i < total; i++) {
		arr[i] = adresses[i].get_city();
	}

	bubble(arr, total);

	for (int i = 0; i < total; i++) {
		std::cout << arr[i] << '\n';
	}

	wipe(adresses);
	wipe(arr);

	/*std::ofstream output("out.txt");
	output << total << '\n';

	for (int i = 0; i < total; i++) {
		adresses[i].get_out(output);
	}*/

	return 0;
}