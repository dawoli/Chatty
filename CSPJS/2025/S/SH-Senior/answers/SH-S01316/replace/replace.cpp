#include<bits/stdc++.h>
using namespace std;

long long n,q;
string s[200005][10];
long long p[200005];
long long pot[200005][10];
string t1,t2,t3,t4;
bool flag=true;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
		for(long long j=0;flag && j<s[i][1].size();j++)
		{
			if(s[i][1][j]!='a' && s[i][1][j]!='b')
			{
				flag=false;
				break;
			}
			if(s[i][2][j]!='a' && s[i][2][j]!='b')
			{
				flag=false;
				break;
			}
		}
	}
	for(long long i=1;flag==false && i<=n;i++)
	{
		long long l=2e9,r=0;
		for(long long j=0;j<s[i][1].size();j++)
			if(s[i][1][j]!=s[i][2][j])
			{
				l=min(l,j),
				r=max(r,j);
			}
		if(l==2e9 && r==0)
			continue;
		s[i][3]=s[i][1].substr(l,(r-l+1));
		s[i][4]=s[i][2].substr(l,(r-l+1));
		p[i]=l;
	}
	if(flag)
	{
		for(int i=1;i<=n;i++)
		{
			long long post1=s[i][1].find("b");
			long long post2=s[i][2].find("b");
			pot[i][1]=post1;
			pot[i][2]=post2;
			pot[i][0]=s[i][1].size();
		}
	}
	while(q--)
	{
		cin>>t1>>t2;
		if(flag)
		{
			long long post1=t1.find("b");
			long long post2=t2.find("b");
			long long ans=0;
			if(! (0<=post1&&post1<=t1.size()&&0<=post2&&post2<=t2.size()&&t1.size()==t2.size()) )
			{
				cout<<0<<endl;
				continue;
			}
			for(int i=1;i<=n;i++)
			{
				if(pot[i][1]-pot[i][2]==post1-post2 && pot[i][1]<=post1 && pot[i][2]<=post2)
					if(pot[i][0]-pot[i][1]<=t1.size()-post1 && pot[i][0]-pot[i][2]<=t1.size()-post2)
						ans++;
			}
			cout<<ans<<endl;
		}
		else
		{
			if(t1.size() != t2.size())
			{
				cout<<0<<endl;
				continue; 
			}
			long long l=2e9,r=0,ans=0;
			for(long long i=0;i<t1.size();i++)
				if(t1[i]!=t2[i])
				{
					l=min(l,i),
					r=max(r,i);
				}
			t3=t1.substr(l,(r-l+1));
			t4=t2.substr(l,(r-l+1));
			for(int i=1;i<=n;i++)
				if(s[i][3]==t3 && s[i][4]==t4)
				{
					long long szt=t1.size();
					long long pst=l-p[i];
					if(pst+s[i][1].size() > t1.size())
						continue;
					string t5=t1.substr(pst,s[i][1].size());
					if(t5==s[i][1])
						ans++;
				}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
