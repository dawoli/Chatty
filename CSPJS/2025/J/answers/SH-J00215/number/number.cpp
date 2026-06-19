#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int ans[1000007];
	for(int i=0;i<1000007;i++){
		ans[i]=-1;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			ans[i]=int (s[i]-'0');
		}
	}
	sort(ans,ans+1000007);
	if(ans[1000006]==0){
		cout<<'0';
		return 0;
	}
	for(int i=1000006;i>0;i--){
		if(ans[i]!=-1){
			cout<<ans[i];
		}
		else{
			break;
		}
	}
	return 0;
}
