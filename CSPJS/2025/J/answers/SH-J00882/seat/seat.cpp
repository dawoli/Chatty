#include <iostream>
#include <algorithm>

using namespace std;

int seat[11][11];
int n, m;
int score[101];
int N, M;


bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin>>n>>m;
	int TEMP = n*m;
	int MY_SCORE = 0;
	cin>>score[1];
	MY_SCORE = score[1];
	for(int i = 2; i <= TEMP ; i++)
	{
		cin>>score[i];
	}
	sort(score+1, score+1+TEMP, cmp);
	

	int x = 1, y = 1;
	bool FLAG = true;
	for(int i=1; i<=TEMP; i++)
	{
		if(score[i] == MY_SCORE)
		{
			cout<<x<<" "<<y<<endl;
			break;
		}
		if((y == n || y == 1) && !FLAG)
		{
			FLAG = true;
			x++;
			continue;
		}
		FLAG = false;
		if(x%2 == 0)
		{
			y--;
		}
		else{
			y++;
		}
	}
	return 0;
	
}
