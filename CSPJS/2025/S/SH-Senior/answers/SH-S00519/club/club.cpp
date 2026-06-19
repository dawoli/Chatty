#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][4];
int pos[N];
int dt[N],k;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	long long sum=0;
	while(t--)
	{
		sum=0;
		memset(dt,0,sizeof(dt));
		k=0;
		int cnt1=0,cnt2=0,cnt3=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			sum+=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				pos[i]=1;
				cnt1++;
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				pos[i]=2;
				cnt2++;
			}else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
				pos[i]=3;
				cnt3++;
			}
		}
		int limit=n/2;
		if(cnt1<=limit&&cnt2<=limit&&cnt3<=limit)
		{
			cout<<sum<<endl;
		}else{
			if(cnt1>limit)
			{
				int l=cnt1-limit;
				for(int i=1;i<=n;i++)
				{
					if(pos[i]==1)
					{
						k++;
						dt[k]=a[i][1]-max(a[i][2],a[i][3]);
					}
				}
				sort(dt+1,dt+k+1);
				for(int i=1;i<=l;i++)
				{
					sum-=dt[i];
				}
				cout<<sum<<endl;
			}
			if(cnt2>limit)
			{
				int l=cnt2-limit;
				for(int i=1;i<=n;i++)
				{
					if(pos[i]==2)
					{
						k++;
						dt[k]=a[i][2]-max(a[i][1],a[i][3]);
					}
				}
				sort(dt+1,dt+k+1);
				for(int i=1;i<=l;i++)
				{
					sum-=dt[i];
				}
				cout<<sum<<endl;
			}
			if(cnt3>limit)
			{
				int l=cnt3-limit;
				for(int i=1;i<=n;i++)
				{
					if(pos[i]==3)
					{
						k++;
						dt[k]=a[i][3]-max(a[i][2],a[i][1]);
					}
				}
				sort(dt+1,dt+k+1);
				for(int i=1;i<=l;i++)
				{
					sum-=dt[i];
				}
				cout<<sum<<endl;
			}
		}
	}
	return 0;
 } 
