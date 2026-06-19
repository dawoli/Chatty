#include<bits/stdc++.h>
using namespace std;

int cnt[10];
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]>0){
			cout<<i;
			cnt[i]--;
		}
	}
	
	
	
	
	
	return 0;
}
