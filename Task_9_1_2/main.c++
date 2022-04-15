#include "byte.h"

#include <iostream>
#include <vector>

using std::vector;
using std::ios;

int main() {

	int bytes_number = 0;

	std::cin >> bytes_number;

	vector<Byte> bytes;
	bytes.reserve(bytes_number);

	int temp_data = 0, temp_mask = 0;

	std::cin.unsetf(ios::dec);
	std::cin.setf(ios::hex);

	for (size_t i = 0; i < bytes_number; i++)
	{
		std::cin >> temp_data >> temp_mask;
		bytes.push_back(Byte(temp_data, temp_mask));
	}

	int left_byte_number = 0, right_byte_number = 0;

	char operation_symbol = (char)32;

	while (std::cin >> left_byte_number >> operation_symbol >> right_byte_number)
	{
		if (operation_symbol == '&')
		{
			bytes.at(left_byte_number - 1) 
				= bytes.at(left_byte_number - 1) & bytes.at(right_byte_number - 1);
		}
		else
		{
			bytes.at(left_byte_number - 1) 
				= bytes.at(left_byte_number - 1) | bytes.at(right_byte_number - 1);
		}
	}

	std::cout.width(2);
	std::cout.fill('0');

	std::cout << std::hex << std::uppercase 
		<< bytes.at(left_byte_number - 1).get_data();

	return 0;
}