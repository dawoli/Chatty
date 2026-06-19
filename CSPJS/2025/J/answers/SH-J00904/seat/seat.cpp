#include<bits/stdc++.h>
using namespace std;

int n,m,a[1000];

int main()
{
	ifstream in("seat.in");
	ofstream out("seat.out");
	in>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		in>>a[i];
	}
	int b=a[0],c=0;
	for(int i=1;i<n*m;i++)
	{
		if(a[i]>b)
		{
			c++;
		}
	}
	int h=c%n;
	int l=c/n;
	if(l%2==1)
	{
		h=n-l;
	}
	out<<l+1<<' '<<h+1;
	return 0;
}

