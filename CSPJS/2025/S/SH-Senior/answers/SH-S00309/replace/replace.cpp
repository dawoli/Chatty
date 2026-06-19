#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],b[200005];
string q1
set s;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		a[i]=s1.find('b')-s2.find('b');
		s.insert(a[i]);
		b[i]=s1.find('b');
	}
}

