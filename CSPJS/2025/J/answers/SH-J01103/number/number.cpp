#include <iostream>
#include <fstream>
#include <array>

using namespace std;

int main() {
	freopen("number.out", "wb", stdout);
	
	ifstream sin("number.in");
	array<int, 10> bitmap = {0};
	
	char result;
	while (sin.good()) {
		sin.read(&result, 1);
		if ('0' <= result && result <= '9')
		{
			bitmap[result - '0']++;
		}
	}
	
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < bitmap[i]; j++)
		{
			cout << (char)(i + 48);
		}
	}
	
	return 0;
}

