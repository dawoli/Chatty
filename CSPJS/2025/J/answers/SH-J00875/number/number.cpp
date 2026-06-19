#include<bits/stdc++.h>
#define int long long
using namespace std;
string s; 
int a[1000005];
int aa;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int t=s.size();
	s=" "+s;
	for(int i=1;i<=t;i++){
		if((int)s[i]>=48&&(int)s[i]<=57){
			a[aa+1]=(int)s[i]-48;
			aa++;
		}
	}
	sort(a+1,a+1+aa,cmp);
	for(int i=1;i<=aa;i++){
		cout<<a[i];
	}
}
