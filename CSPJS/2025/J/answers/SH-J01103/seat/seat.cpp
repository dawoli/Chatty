#include <iostream>
#include <vector>

using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "wb", stdout);
	
	int n = 0, m = 0;
	
	cin >> n >> m;
	// n -> ÐÐ, m -> ÁÐ 
	int nn = 1, mm = 1;
	bool minusing = false;
	
	auto shift = [&]() {
		nn = minusing ? nn - 1 : nn + 1;
		
		if (nn < 1 || nn > n)
		{
			minusing = !minusing;
			mm++;
			nn = minusing ? nn - 1 : nn + 1;
		}
	};
	
	vector<int> scores;
	scores.reserve(m * n);
	
	for (int l = 0; l < m * n; l++)
	{
		cin >> scores[l];
	}
	
	int current = scores[0];
	
	for (int l = 0; l < m * n; l++)
	{
		for (int l2 = l + 1; l2 < m * n; l2++)
		{
			if (scores[l] < scores[l2])
			{
				// swap two numbers!
				scores[l] = scores[l] + scores[l2];
				scores[l2] = scores[l] - scores[l2];
				scores[l] = scores[l] - scores[l2];
			}
		}
	}
	
	for (int l = 0; l < m * n; l++)
	{
		if (scores[l] == current)
		{
			break;
		}
		shift();
	}
	
	cout << mm << " " << nn;
}
