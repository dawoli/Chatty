#include<bits/stdc++.h>
using namespace std;
string s;
long long cnt[10];
string ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			cnt[int(s[i]-'0')]++;
		}
	}
	for(auto it=9;it>=0;it--){
		int x=it,y=cnt[it];
		if(it==0&&ans==""){
			ans="0";
			break;
		} 
		for(int i=1;i<=y;i++){
			ans+=char(x+'0');
		}
	}
	cout<<ans;
	return 0;
}

