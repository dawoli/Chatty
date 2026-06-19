#include<bits/stdc++.h>
using namespace std;
int cnt[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int n = s.size();
	for(int i = 0;i < n;i++){
		if(s[i] >= '0' and s[i] <= '9'){
			cnt[s[i] - '0']++;
		}
	}
	for(int i = 9;i >= 0;i--){
		if(cnt[i] != 0){
			while(cnt[i]--){
				printf("%d",i);
			}
		}
	}
	return 0;
}
