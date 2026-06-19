#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5*2+10;
int pre[MAXN],v[MAXN],vlen;
string s1[MAXN],s2[MAXN];
void func(string s)
{
	memset(pre,0,sizeof(pre));
	int n=(int)s.size();
	for(int i=1;i<n;++i)
	{
		int j=pre[i-1];
		while(j>0&&s[i]!=s[j])
			j=pre[j-1];
		if(s[i]==s[j])
			j++;
		pre[i]=j;
	}
	return;
}
void KMP(string a,string b)
{
	vlen=0;
	memset(v,0,sizeof(v));
	string cur=b+"#"+a;
	int sz1=a.size(),sz2=b.size();
	func(cur);
	for(int i=sz2+1;i<=sz1+sz2;i++)
		if(pre[i]==sz2)
			v[vlen++]=i-sz2*2;
	return;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;++i)
		cin>>s1[i]>>s2[i];
	/*debug1
	for(int i=1;i<=n;++i)
		cout<<s1[i]<<" "<<s2[i]<<"\n";
	*/
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		if(t1.size()!=t2.size())
		{
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;++i)
		{
			KMP(t1,s1[i]);
			/*debug2
			for(int j=0;j<vlen;++j)
				cout<<v[j]<<"¡¡";
			printf("\n"); 
			*/
			for(int j=0;j<vlen;++j)
			{	
				int p=0;
				string t="";
				for(;p<v[j];p++)
					t+=t1[p];
				for(;p<v[j]+s1[i].size();p++)
					t+=s2[i][p-v[j]];
				for(;p<t1.size();p++)
					t+=t1[p];
				//cout<<t<<"\n"; debug3
				if(t==t2)
					ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
