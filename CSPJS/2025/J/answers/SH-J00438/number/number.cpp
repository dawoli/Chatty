#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using i64=long long;
const int N=1e6+5;
int n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	s=' '+s;
	vector<int> v;
	for (int i=1;i<=n;i++)
	{
		if ('0'<=s[i] && s[i]<='9')
		{
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end(),greater<int>());
	for (int i=0;i<v.size();i++)
	{
		cout<<v[i];
	}
	cout<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

