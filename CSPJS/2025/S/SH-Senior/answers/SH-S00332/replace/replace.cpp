#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10,P=29;
int n,q;
string s[4];
unsigned long long st[N],ed[N],len[N],pr[N],df[N],lst[N];

bool check(int i,int start,int end)
{
//	cout << i << ' ' << st[i] << ' ' << ed[i] << ' ' << start << ' ' << end << endl;
	if(st[i] > start || s[1].length()-end < len[i]-ed[i] || end-start != ed[i]-st[i])	return false;
	unsigned long long hs=1;
//	cout << start-st[i] << ' ' << end+len[i]-1-ed[i] << endl;
	for(int cur=start-st[i];cur<start;cur++)	hs=hs*P+s[1][cur]-'a';
//	cout << hs << ' ' << pr[i] << endl;
	if(hs != pr[i])	return false;
	hs=1;
	for(int cur=start;cur<=end;cur++)	hs=hs*P+s[1][cur]-'a',hs=hs*P+s[2][cur]-'a';
	if(hs != df[i])	return false;
	hs=1;
	for(int cur=end+1;cur<=end+len[i]-1-ed[i];cur++)	hs=hs*P+s[1][cur]-'a';
	if(hs != lst[i])	return false;
//	cout << "!!!" << endl;
	return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		pr[i]=df[i]=lst[i]=1;
		cin >> s[1] >> s[2];
		st[i]=0,len[i]=s[1].length();
		while(s[1][st[i]] == s[2][st[i]])
		{
			pr[i]=pr[i]*P+s[1][st[i]]-'a';
			++st[i];
		}
		string tmp1="",tmp2="";
		for(int m=st[i];s[1][m];m++)
		{
			tmp1+=s[1][m],tmp2+=s[2][m];
			if(s[1][m] != s[2][m])
			{
				for(int j=0;tmp1[j];j++)
					df[i]=df[i]*P+tmp1[j]-'a',df[i]=df[i]*P+tmp2[j]-'a';
				ed[i]=m;
				tmp1="",tmp2="";
			}
		}
		for(int j=0;tmp1[j];j++)
			lst[i]=lst[i]*P+tmp1[j]-'a';
		
	}
	
	for(int i=1;i<=q;i++)
	{
		cin >> s[1] >> s[2];
		if(s[1].length() != s[2].length())
		{
			cout << 0 << endl;
			continue;
		}
		int start=0,end;
		while(s[1][start] == s[2][start])++start;
		for(int m=start;s[1][m];m++)
		{
			if(s[1][m] != s[2][m])	end=m;
		}
		int cnt=0;
		for(int j=1;j<=n;j++)	cnt+=check(j,start,end);
		cout << cnt << endl;
	}
	return 0;
}

