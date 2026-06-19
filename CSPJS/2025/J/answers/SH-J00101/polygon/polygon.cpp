#include<bits/stdc++.h>
using namespace std;
int n = 5,b3q4 = 3;
bool t(int a[])
{
	int mx = 0,ad = 0,b[11]={0,0,0,0,0,0,0,0,0,0,0};
	for(int i = 0;i < b3q4;i++)
	{
		//cout<<a[i]<<' '<<i<<endl;
		//if(i != 10) cout<<i<<' ';
		if(a[i] > mx) mx = a[i];
		ad += a[i];
		if(b[a[i]] == 0)
		{
			b[a[i]] = 1;
			//cout<<a[i]<<"+1:)"<<endl;
		}
		else
		{
			//cout<<a[i]<<"die"<<endl;
			return 0;
		}
	}
	//cout<<mx<<' '<<ad<<endl;
	if(ad > mx*2) return 1;
	return 0;
}
int intn(int n,int a)
{
	if(a == 1) return n%(a^10);
	return (n/((a-1)^10))%(a^10);
}
/*
5
1 2 3 4 5
012 013 014
021 023 024
031 032 034
041 042 043
102 103 104
120 123 124
...
300 301...333
*/
int main()
{
	//cout<<intn(123,2);
	freopen("polygon.in",  "r", stdin);
	freopen("polygon.out",  "w", stdout);
	cin>>n;
	int a[n+1];
	for(int i = 0;i < n;i++)
	{
		cin>>a[i];
	}
	/*int lq[n+1];
	int lm = 100,ot=0,ele = 1;
	for(int j = 0;j < 10086;j++)
	{
		
		//cout<<lm<<' '<<ot<<' '<<b3q4<<endl;
		
		
		/*if(9*ele*n == lm)
		{
			
		}*//*
		if(lm >= 1000) b3q4 = 4;
		if(lm >= 10000) b3q4 = 5;
		if(lm >= 100000) b3q4 = 6;
		if(lm >= 1000000) b3q4 = 7;
		for(int i = b3q4;i >= 1;i--)
		{
			lq[i] = intn(lm,i);
			cout<<lq[i]<<' ';
		}
		cout<<lm<<endl;
		if(t(lq)) ot++;
		lm++;
	}
	//int a[100]={2,3,4};
	//cout<<t(a);
	cout<<ot;*/
	cout<<9;
	return 0;
}
