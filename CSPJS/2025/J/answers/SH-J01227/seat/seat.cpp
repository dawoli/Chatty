#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int smaller = 0,littleR; 
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			int x;
			cin >> x;
			if(i == 1 && j == 1)
			{
			    littleR = x;
			    continue;
			}
			if(x > littleR)smaller++;
		}
	}
	int wei = smaller + 1;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			int seat;
			if(j % 2)seat = (j-1) * n + i;
			else seat = n * j - i + 1;
			if(seat == wei)
			{
				cout << j << " " << i << endl;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
