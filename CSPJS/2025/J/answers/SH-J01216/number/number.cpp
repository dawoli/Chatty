#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;int a[N];bool f=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;int zz=0;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9'){
			a[++zz]=s[i]-48;
			if(s[i]!=0) f=1;
		}
	if(!f) {
		cout<<0;
		return 0;
	}
	sort(a+1,a+zz+1);
	for(int i=zz;i>=1;i--)
		cout<<a[i];
	return 0;
}
