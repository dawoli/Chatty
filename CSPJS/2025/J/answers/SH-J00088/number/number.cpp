#include<bits/stdc++.h>
using namespace std;
string s;
int n,cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]--){
			printf("%d",i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
