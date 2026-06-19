#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long n;
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')
		s[i]=a[i];
	}
	sort(a[0],a[n-1],greater<ll>());
	for(int i=n;i<=0;i++) cout<<a[i];
	return 0;
}
