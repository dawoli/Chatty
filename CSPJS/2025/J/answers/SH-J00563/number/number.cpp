#include <iostream>

using namespace std;

int bucket[15];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s; 
	cin >> s;
	
	for (const char &c : s)
	{
		if (c >= '0' && c <= '9')
		{
			++bucket[(c - '0')];
		}
	}
	
	string ans = "";
	for (int i = 9; i >= 0; i--)
	{
		while (bucket[i]--)
		{
			ans += to_string(i);
		}
	}
	
	cout << ans << endl;

	fclose(stdin);
	fclose(stdout); 
	return 0;
}

