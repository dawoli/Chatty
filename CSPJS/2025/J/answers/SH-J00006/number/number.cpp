#include<bits/stdc++.h>
using namespace std;
string s;
long long cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if('0'<=s[i]&&s[i]<='9'){
			cnt[s[i]-'0']++;
		} 
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]--)cout<<i;
	}
}
