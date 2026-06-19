#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
int cnt=9;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.length()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-48]++;
		}
	}
	while(cnt>=0){
		if(a[cnt]==0){
			if(cnt==0)break;
			cnt--;
		}
		if(a[cnt]!=0){
			cout<<cnt;
			a[cnt]--;
		}
	}
	return 0;
}
