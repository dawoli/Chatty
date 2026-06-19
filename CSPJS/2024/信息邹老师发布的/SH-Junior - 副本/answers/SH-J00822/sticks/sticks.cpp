#include<bits/stdc++.h>

using namespace std;

void check(int number,int index)
{
	if(index == 0)
	{
		
	} 
	
	return; 
} 
// 0 6
// 1 2
// 2 5
// 3 5
// 4 4
// 5 5
// 6 6
// 7 3
// 8 7
// 9 6

//6 2 5 4 3 7
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		int number;
		cin >> number;
		check(number,0); 
	} 
	return 0; 
} 
