# include <bits/stdc++.h>//ÕâÌâÊ«ÈË£¿£¿£¿ 
using namespace std;
string s;
int ans[1000005]={0};
int cnt=0,res=0;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			ans[i]=s[i]-'0';
			cnt++;
		}
	}
	sort(ans,ans+n-1,cmp);
	for(int i=0;i<cnt;i++)
	{
		cout<<ans[i];
	}
	return 0;
}
