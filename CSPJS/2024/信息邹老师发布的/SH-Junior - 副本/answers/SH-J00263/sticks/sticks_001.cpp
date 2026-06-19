#include <bits/stdc++.h>
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6};
long long bb[100005];
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		fill(bb,bb+n,1e9);
		for(int i=n;i>=0;i--)
		{
			for(int j=0;j<10;j++)
			{
				if(i+num[j]>n)continue;
				if(j==0 &&bb[i+num[j]]==0)continue;
				bb[i]=min(bb[i],bb[i+num[j]]*10+j);
			}
		}
		if(bb[0]==1e9)cout<<-1<<endl;
		else cout<<bb[0]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
