#include<bits/stdc++.h>
using namespace std;
string s;
long long t,a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9') a[t]=s[i]-48,t++;
	}
	sort(a,a+t);
	if(a[t-1]==0) cout<<0;
	else{
		for(int i=t-1;i>=0;i--){
			cout<<a[i];
		}
	}
	return 0;
}
//phigrosphigros11451411451419198101919810
//AKAKAKAKAKAKAKAKAK
//rp++rp++rp++rp++
