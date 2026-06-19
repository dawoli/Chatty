#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
pair<LL,string> stick_num[6]={{6,"0"},{2,"1"},{5,"2"},{4,"4"},{3,"7"},{7,"8"}};
LL n=0;
bool str_comp(string&a,string&b)
{
	if(a=="?")
		return true;
	if(a.size()!=b.size())
		return a.size()>b.size();
	for(LL i=0;i<a.size();++i)
		if(a[i]!=b[i])
			return a[i]>b[i];
	return false;
}

string making_stick_num(vector<string>&memo,LL cur)
{
	if(memo[cur]!="?")
		return memo[cur];
	for(LL i=0;i<=5;++i)
		if(cur>=stick_num[i].first)
		{
			string tp=making_stick_num(memo,cur-stick_num[i].first);
			string tmp=(i==0&&cur==n?"6":stick_num[i].second)+tp;
			if(tp!="x"&&str_comp(memo[cur],tmp))
				memo[cur]=tmp;
		}
	if(memo[cur]=="?")
		memo[cur]="x";
	return memo[cur];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	LL t=0;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<string>memo(n+1,"?");
		memo[0]="";
		memo[1]="x";
		making_stick_num(memo,n);
		cout<<(memo[n]=="x"?"-1":memo[n])<<endl;
	}
	return 0;
}
