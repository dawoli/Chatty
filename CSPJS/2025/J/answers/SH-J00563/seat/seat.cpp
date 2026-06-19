#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;
int scores[N];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m, R_score = 0;
	cin >> n >> m;
	
	for (int i = 1; i <= n * m; i++)
	{
		cin >> scores[i];
		if (i == 1)
			R_score = scores[i]; 
	}
	
	sort(scores + 1, scores + 1 + n * m);
	
	int pos = lower_bound(scores + 1, scores + 1 + n * m, R_score) - scores;
	// count reverse
	pos = n * m - pos + 1;

	int mm = (pos - 1) % n + 1;
	int nn = (pos - 1) / n + 1;
	if (!(nn & 1))
		mm = n + 1 - mm;
	
	cout << nn << " " << mm << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}

