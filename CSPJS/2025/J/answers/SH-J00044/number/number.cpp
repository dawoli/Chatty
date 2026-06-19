#include<bits/stdc++.h>
#define N 1000005
typedef long long ll;
using namespace std;
ll a,x[N];
string s,t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c:s) if(isdigit(c)) t+=c;
	for(char c:t) x[++a]=c-'0';
	sort(x+1,x+1+a);
	for(ll i=a;i>=1;i--) cout<<x[i];
	return 0;
}
