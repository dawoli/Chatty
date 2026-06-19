#include<bits/stdc++.h>
using namespace std;
map<string,long long> m;
const string s[52]={"DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK","CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK","HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK","SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK"};
string a;
long long n;
int main()
{
	if(true)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		freopen("poker.in","r",stdin);
		freopen("poker.out","w",stdout);		
	}
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		m[a]++;
	}
	n=0;
	for(int i=0;i<52;i++)
		if(m[s[i]]==0)
			n++;
	cout<<n<<"\n";
	return 0;
}
