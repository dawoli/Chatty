#include<bits/stdc++.h>
using namespace std;
int t,n,num[8]={-1,-1,1,7,4,2,0,8},k,m,a[50001]={0},j,ai;

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;l++)
	{
		cin>>n;
		k=n/7;
		m=-1;
		if(n%7==0)
		{
			for(int i=1;i<=k;i++)
			{
				cout<<"8";
			}
			cout<<endl;
			continue;
		}
		if(n<=1)
		{
			cout<<"-1"<<endl;
			continue;
		}
		k++;
		j=k;
		while(j!=0)
		{
			if(m==-1)
			{
				num[6]=6;
			}
			else
			{
				num[6]=0;
			}
			if(j==1)
			{
				a[j]=num[n];
				break;
			}
			m=n-(j-1)*7;
			a[j]=10;
			for(int i=m;i<=7;i++)
			{
				if(a[j]>num[i]&&num[i]>=0)
				{
					a[j]=num[i];
					ai=i;
				}
			}
			n-=ai;
			if(m==ai)
			{
				break;
			}
			j--;
		}
		for(int i=k;i>=j;i--)
		{
			cout<<a[i];
		}
		for(int i=j-1;i>=1;i--)
		{
			cout<<"8";
		}
		cout<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
