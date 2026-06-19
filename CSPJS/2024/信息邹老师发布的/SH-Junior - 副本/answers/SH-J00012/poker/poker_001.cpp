#include <fstream>

std::ifstream fin("poker.in");
std::ofstream fout("poker.out");

bool flag[5][15];

int main()
{
	int n;
	fin >> n;

	for(int i = 1; i <= n; ++i) {
		char a, temp;
		int number = 0, type = 0;
		fin >> a >> temp;

		if (temp == 'A')number = 1;
		else if(temp == '2') number = 2;
		else if(temp == '3') number = 3;
		else if(temp == '4') number = 4;
		else if(temp == '5') number = 5;
		else if(temp == '6') number = 6;
		else if(temp == '7') number = 7;
		else if(temp == '8') number = 8;
		else if(temp == '9') number = 9;
		else if(temp == 'T') number = 10;
		else if(temp == 'J') number = 11;
		else if(temp == 'Q') number = 12;
		else if(temp == 'K') number = 13;

		if(a == 'D') type = 1;
		else if(a == 'C') type = 2;
		else if(a == 'H') type = 3;
		else if(a == 'S') type = 4;

		flag[type][number] = true;
	}

	int ans = 0;

	for(int i = 1; i <= 4; ++i)
		for(int j = 1; j <= 13; ++j)
			if(!flag[i][j]) ans++;

	fout << ans;
}
