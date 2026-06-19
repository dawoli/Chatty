/**************
 * T3 replace 
 * ¹À·Ö: 0
 **************/
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <map> 
using namespace std;
int n,q;
vector<pair<string,string> >m;
int main()
{
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	while(n--)
	{
		string a,b;
		cin >>a >>b;
		m.push_back({a,b});
	}
	while(q--)
	{
		string a,b;
		cin >> a >> b;
		int s=0;
		if(a.length()!=b.length())
		{
			cout << "0" << endl;
			continue;
		}
		for(auto i:m)
		{
			string h=i.first;
			int p=a.find(h);
			if(p==-1)continue;
			int l=h.length();
			string x=a.substr(0,p),y=h,z=a.substr(p+l);
//			cout << x << " " << y << " " << z << endl;
			string w=x+i.second+z;
			if(w==b)s++;
		}
		cout << s << endl;
	}
	return 0;
}
