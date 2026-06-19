#include<bits/stdc++.h>
using namespace std;
string a;
int ans[1000005],ansi=0;
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			ans[++ansi]=(int)(a[i]-'0');
		}
	}
	sort(ans+1,ans+ansi+1);
	for(int i=ansi;i>=1;i--)cout<<ans[i];
	return 0;
}
