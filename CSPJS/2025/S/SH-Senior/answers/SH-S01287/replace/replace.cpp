#include<bits/stdc++.h>
using namespace std;
string s[200011];
string c[200011];
char stemp[5000011];
char ctemp[5000011];
vector<pair<pair<int,int> ,int > > edges[5000011];
int cx[5000011];
int ans[200011];
vector<int> v;
int maxn=0;
void modify(int x,int s)
{
	while(x<=maxn)
	{
		cx[x]+=s;
		x+=(x&(-x));
	}
}
int check(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=cx[x];
		x-=(x&(-x));
	}
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	long long sum=0;
	long long temp1=0,temp2=0,temp3=0,temp4=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",stemp+1);
		scanf("%s",ctemp+1);
		int m=strlen(stemp+1);
		sum+=m;
		for(int j=1;j<=m;j++)
		{
			s[i].push_back(stemp[j]),c[i].push_back(ctemp[j]);
			if(stemp[j]=='a')temp1++;
			else if(stemp[j]=='b')temp2++;
			if(ctemp[j]=='a')temp3++;
			else if(ctemp[j]=='b')temp4++;
		}
		maxn=max(maxn,m);
	}
	if(temp2==n&&temp4==n&&temp1+temp2==sum&&temp3+temp4==sum)
	{
		for(int i=1;i<=n;i++)
		{
			int temp=s[i].size();
			int pres=0,sufs=0;
			for(int j=0;j<=temp-1;j++)
			{
				if(s[i][j]=='a')pres++;
				else break;
			}
			for(int j=temp-1;j>=0;j--)
			{
				if(s[i][j]=='a')sufs++;
				else break;
			}
			int prec=0,sufc=0;
			for(int j=0;j<=temp-1;j++)
			{
				if(c[i][j]=='a')prec++;
				else break;
			}
			for(int j=temp-1;j>=0;j--)
			{
				if(c[i][j]=='a')sufc++;
				else break;
			}
			if(pres==prec&&sufs==sufc)
			{
				continue;
			}
			prec++,pres++,sufc++,sufs++;
			edges[max(prec,pres)-min(prec,pres)+1].push_back({{min(prec,pres),0},min(sufc,sufs)});
		}
		for(int i=1;i<=q;i++)
		{
			scanf("%s",stemp+1);
			scanf("%s",ctemp+1);
			int m=strlen(stemp+1);
			maxn=max(maxn,m);
			int pres=0,sufs=0;
			for(int j=1;j<=m;j++)
			{
				if(stemp[j]=='a')pres++;
				else break;
			}
			for(int j=m;j>=1;j--)
			{
				if(stemp[j]=='a')sufs++;
				else break;
			}
			int prec=0,sufc=0;
			for(int j=1;j<=m;j++)
			{
				if(ctemp[j]=='a')prec++;
				else break;
			}
			for(int j=m;j>=1;j--)
			{
				if(ctemp[j]=='a')sufc++;
				else break;
			}
			prec++,pres++,sufc++,sufs++;
			edges[max(prec,pres)-min(prec,pres)+1].push_back({{min(prec,pres),i},min(sufc,sufs)});
		}
		for(int i=1;i<=maxn;i++)
		{
			for(auto x:v)modify(x,-1);
			v.clear();
			sort(edges[i].begin(),edges[i].end());
			for(auto x:edges[i])
			{
				if(x.first.second==0)modify(x.second,1),v.push_back(x.second);
				else ans[x.first.second]=check(x.second);
			}
		}
		for(int i=1;i<=q;i++)
		{
			printf("%d\n",ans[i]);
		}
		return 0;
	}
	else if(q==1)
	{
		scanf("%s",stemp+1);
		scanf("%s",ctemp+1);
		int m=strlen(stemp+1);
		int pre=0,suf=0;
		for(int j=1;j<=m;j++)
		{
			if(stemp[j]==ctemp[j])pre++;
			else break;
		}
		for(int j=m;j>=1;j--)
		{
			if(stemp[j]==ctemp[j])suf=j;
			else break;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int temp=s[i].size();
			int pretemp=0,suftemp=0;
			for(int j=0;j<=temp-1;j++)
			{
				if(s[i][j]==c[i][j])pre++;
				else break;
			}
			for(int j=temp-1;j>=0;j--)
			{
				if(s[i][j]==c[i][j])suf=j;
				else break;
			}
			if(suftemp-pretemp+1!=suf-pre+1)continue;
			bool cc=false;
			for(int j=pretemp+1;j<=suftemp-1;j++)
			{
				if(stemp[j-pretemp+pre]!=s[i][j-1]||ctemp[j-pretemp+pre]!=c[i][j-1])
				{
					cc=true;break;
				}
			}
			if(cc==true)continue;
			if(pretemp>pre)continue;
			for(int j=pretemp;j>=1;j--)
			{
				if(stemp[pre-(pretemp-j)]!=s[i][j-1])
				{
					cc=true;break;
				}
			}
			if(suftemp>suf)continue;
			for(int j=suftemp;j<=temp;j++)
			{
				if(stemp[suf+suftemp-j]!=s[i][j-1])
				{
					cc=true;break;
				}
			}
			if(cc==true)continue;
			ans++;
		}
		printf("%d\n",ans);
	}
}
