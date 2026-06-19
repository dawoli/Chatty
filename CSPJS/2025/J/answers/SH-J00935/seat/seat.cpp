#include<bits/stdc++.h>
using namespace std;
int arr[110]={0};
int arr_1[240]={0};
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k=2*m;
	for(int i=0;i<k/2;i++)
	{
		arr_1[i]=i+1;
		arr_1[2*m-1-i]=i+1;
	}
//	for(int i=0;i<2*m;i++)
//	{
//		cout<<arr_1[i]<<' ';
//	}
	for(int i=0;i<n*m;i++)
	{
		cin>>arr[i];
	}
	int tgt=arr[0];
	sort(arr,arr+(m*n));
	int x=1,y=1;
	for(int i=0;i<n*m;i++)
	{
		if(arr[i]==tgt)
		{
			break;
		}
		if(x==n)
		{
			x=1;
		}
		if(y==k)
		{
			y=1;
		}
		x++;
		y++;
	}
	cout<<x<<' '<<arr_1[y];
	return 0
}
