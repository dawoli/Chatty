#include <iostream>
#include <vector>
using namespace std;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	unsigned int n = 0, k = 0;
	cin >> n >> k;
	vector<unsigned int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
