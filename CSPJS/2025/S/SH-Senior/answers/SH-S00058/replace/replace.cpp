#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("repalce.out", "w", stdout);
	
	srand(time(NULL));
	int n, m;
	cin >> n >> m;
	
	while(m --)
	{
		int ans = rand() % n;
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
