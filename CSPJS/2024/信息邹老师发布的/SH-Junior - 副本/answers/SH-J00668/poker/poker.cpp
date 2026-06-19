#include<iostream>
using namespace std;
int l, y = 52;
int arr[111];
int lyx[111];
int main()
{
	freopen("poker.in", 'r',stdin);
	freopen("poker.out",'w',stdout);
	cin>>l;
	for(int i=1;i<=l;i++)
	{
		string y;
		cin>>y;
		for(int j=0;j<y.size();j++) arr[i] += int(y[j]);  
	}
	for(int i=1;i<=l;i++) 
		for(int j=1;j<=l;j++)
			if(i!=j&&arr[i]==arr[j]) arr[j] = 0;
	for(int i=1;i<=l;i++) if(arr[i]!=0) y--;
	cout<<y;
	return 0;	 
} 
