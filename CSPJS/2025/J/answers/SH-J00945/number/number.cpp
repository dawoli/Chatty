#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> a;
bool cmp(int a,int b){return a>b;}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s.size()==1)
	{
		cout<<s<<endl;
		return 0;
	}
	a.clear();
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a.push_back(s[i]-48);
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<a.size();i++)printf("%d",a[i]);
	printf("\n");
	return 0;
} 
