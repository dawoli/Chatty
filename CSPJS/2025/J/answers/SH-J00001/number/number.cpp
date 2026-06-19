#include<bits/stdc++.h>
using namespace std;
long long cnt[10];
bool flag=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long t=s.size();
	for(long long i=0;i<t;i++){
		if(s[i]-'0'>=0 and s[i]-'0'<=9){
			cnt[s[i]-'0']++;
			if(s[i]-'0'>0)flag=1;
		}
	}if(!flag){
		cout<<0<<'\n';
		return 0;
	}for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}

