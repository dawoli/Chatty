#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
	int n,arr[100001],brr[100001],maxn=0,minn=200000,s=0,p;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		brr[arr[i]]++;
		maxn=max(arr[i],maxn);
		minn=min(arr[i],minn);
	}
	for(int i=minn+1;i<=maxn;i++)
	{
		if(brr[i]!=0)
		{
			if(brr[minn]<=brr[i])
			{
				n-=brr[minn];
				if(brr[i]-brr[minn]>=p)
				{
					n-=p;
				}
				else 
				{
					n-=(brr[i]-brr[minn]);
					p-=(brr[i]-brr[minn]);
				}
				minn=i;
			}
			if(brr[minn]>brr[i])
			{
				p=brr[minn]-brr[i];
				n-=brr[i];
				minn=i;
			}
		}
	}
	cout<<n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
    fclose(stdout);
    return 0;
}