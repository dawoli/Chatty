#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],ansn,ansm,x,w;
bool cmp(int a,int b)
{
	return a>b; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int h=n*m;
	for(int i = 1;i <= h;i ++)
	{
		cin >> a[i];
	 } 
	x=a[1];
	sort(a+1,a+1+h,cmp);
	for(int i = 1;i <= h;i ++)
	{
		if(a[i]==x)
		{
			w=i;
		}
	}
	//cout << w << endl;
	ansm=(w-1)/n+1;
	w%=n;
	if(w==0)
	{
		if(ansm%2==0) ansn=1;
		else ansn=n; 
	}
	else if(ansm%2==1)ansn=w;
	else ansn=n-w+1;
	
	cout << ansm << " " << ansn;
	return 0; 
}
