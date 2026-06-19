#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int arr[N] = {0};
int t;

int f(int a)
{
	int ans = N;
	for(int i = 2; i <= a / 2; i++)
	{
		int j = a - i;
		if(j >= 8) continue;
		int x;
		if(i == 6 && j != 6) x = 10 * arr[i];
		else if(i != 6 && j == 6) x = 10 * arr[j];
		else if(i == 6 && j == 6) x = 60;
		else x = min(10 * arr[i] + arr[j], 10 * arr[j] + arr[i]);
		ans = min(ans, x);
	}
}

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin>>t;
	arr[1] = -1;
	arr[2] = 1;
	arr[3] = 7;
	arr[4] = 4;
	arr[5] = 2;
	arr[6] = 6;
	arr[7] = 8;
	arr[8] = 10;
	arr[9] = 18;
	arr[10] = 22;
	arr[11] = 20;
	arr[12] = 28;
	while(t--)
	{
		int n;
		cin>>n;
		if(n % 7 == 0)
		{
			for(int i = 1; i <= n / 7; i++) cout<<8;
		}
		else for(int i = 13; i <= n; i++) arr[i] = f(i);
		cout<<arr[n]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
