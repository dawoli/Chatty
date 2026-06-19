#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e5+5;
int t,n,a[MAXN][4],cnt[MAXN];
int num1,num2,num3,sum;
int a1[MAXN],a2[MAXN],a3[MAXN];
void dfs(int pos,int ans){
	if(pos>n)
	{
		sum=max(sum,ans);
		return;
	}
	if(num1+1<=n/2)
	{
		num1++;
		dfs(pos+1,ans+a[pos][1]);
		num1--;
	}
	if(num2+1<=n/2)
	{
		num2++;
		dfs(pos+1,ans+a[pos][2]);
		num2--;
	}
	if(num3+1<=n/2)
	{
		num3++;
		dfs(pos+1,ans+a[pos][3]);
		num3--;
	}
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t-->0){
		cin>>n;
		bool A=true,B=true;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][3]!=0)
				A=B=false;
			if(a[i][2]!=0)
			    A=false;
		}
		if(n<=10)
		{
			num1=num2=num3=sum=0;
			dfs(1,0);
			cout<<sum<<endl;
		}
		else if(A)
		{
			sum=0;
			for(int i=1;i<=n;++i)
			    cnt[i]=a[i][1];
			sort(cnt+1,cnt+n+1);
			for(int i=n;i>n/2;--i)
			    sum+=a[i][1];
			cout<<sum<<endl;
		}
		else if(B)
		{
			for(int i=1;i<=n;++i)
				cnt[i]=a[i][1]-a[i][2];
			sort(cnt+1,cnt+n+1);
			for(int i=n;i>n/2;--i)
			    sum+=cnt[i];
			for(int i=1;i<=n;++i)
			    sum+=a[i][2];
			cout<<sum<<endl;
		}
		else
		{
			num1=num2=num3=sum=0;
			for(int i=1;i<=n;++i)
			{
				if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])
				{
				    sum+=a[i][1];
				    num1++;
					a1[num1]=max(a[i][2]-a[i][1],a[i][3]-a[i][1]);
				}
				else if(a[i][2]>=a[i][1]&&a[i][2]>a[i][3])
				{
				    sum+=a[i][2];
				    num2++;
					a2[num2]=max(a[i][1]-a[i][2],a[i][3]-a[i][2]);
				}
				else
				{
				    sum+=a[i][3];
				    num3++;
					a3[num3]=max(a[i][1]-a[i][3],a[i][2]-a[i][3]);
				}
			}
			if(num1<=n/2&&num2<=n/2&&num3<=n/2)
			    cout<<sum<<endl;
			else
			{
				if(num1>n/2)
				{
					sort(a1+1,a1+num1+1);
					for(int i=num1;i>n/2;--i)
						sum+=a1[i];
				}
				else if(num2>n/2)
				{
					sort(a2+1,a2+num2+1);
					for(int i=num2;i>n/2;--i)
						sum+=a2[i];
				}
				else
				{
					sort(a3+1,a3+num3+1);
					for(int i=num3;i>n/2;--i)
						sum+=a3[i];
				}
				cout<<sum<<endl;
			}
		}
	}
	return 0;
}
