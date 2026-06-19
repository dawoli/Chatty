#include<bits/stdc++.h>
using namespace std;
char a;
int cnt=1;
int s[1000005]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a){
		if(a<='9'&&a>='0'){
			s[cnt]=a-'0';
			cnt++;
		}
	}
	sort(s+1,s+cnt);
	for(int i=cnt-1;i>=1;i--){
		cout<<s[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
