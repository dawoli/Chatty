#include<bits/stdc++.h>
using namespace std;
string s;
int ans[1000005],k=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[++k]=s[i]-'0';
		}
	}
	sort(ans+1,ans+k+1,cmp);
	for(int i=1;i<=k;i++){
		cout<<ans[i];
	}
	return 0;
}
