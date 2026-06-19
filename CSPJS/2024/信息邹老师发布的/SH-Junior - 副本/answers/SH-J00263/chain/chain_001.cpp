#include <bits/stdc++.h>
using namespace std;
int bb[200005];
int lp[200005];
int main()
{
	freopen("chain1.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,kk,q;
		cin>>n>>kk>>q;
		string l[n];
		int le[n];
		for(int i=0;i<n;i++)
		{
			cin>>le[i];
			for(int j=0;j<le[i];j++)
			{
				int a;
				cin>>a;
				l[i]+=a+'0';
			}
		}
		for(int i=0;i<q;i++)
		{
			int r,c;
			cin>>r>>c;
			fill(lp,lp+c+1,-1);
			fill(bb,bb+c+1,1e9);
			bb[c]=0;
			for(int j=c;j>0;j--)
			{
				if(bb[j]==r)continue;
				for(int k=0;k<n;k++)
				{	bool fl=0;
					for(int ll=0;ll<le[k];ll++)
					{
						int x=int(l[k][ll])-'0';
						if(x==j){
						fl=ll;continue;}
						if(fl && (bb[j]+1)<=bb[x] && lp[j]!=k && x-fl<=kk && x-fl>=2){bb[x]=bb[j]+1;lp[x]=k;}
					}
				}
			}
			if(bb[1]==r)cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
