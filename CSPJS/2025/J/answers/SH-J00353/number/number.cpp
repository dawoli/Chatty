#include <bits/stdc++.h>
using namespace std;
string t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	vector<int> a;
	for(int i=0;i<t.size();i++)
		if(isdigit(t[i]))
			a.push_back(t[i]-'0');
	sort(a.begin(),a.end());
	for(int i=a.size()-1;i>=0;i--)
		cout<<a[i];
	cout<<"\n";
	return 0;
}
