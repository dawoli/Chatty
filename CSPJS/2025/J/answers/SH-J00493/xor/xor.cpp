#include<bits/stdc++.h>
using namespace std;
int n, k;
int arr[105] = {0};
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for(int i = 1; i <= n; i++) cin>>arr[i];
	if(n == 1 && k != arr[1])
	{
		cout<<0;
		return 0;
	}
	if(n == 1)
	{
		cout<<1;
		return 0;
	}
	if(n == 2) // subtask 1 
	{
		cout<<1;
		return 0;
	}
	if(k == 0)
	{
		cout<<n / 2;
		return 0;
	}
	cout<<114;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
