#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	int c[10] = {0};
	cin>>s;
	for (int i=0;i<s.length();++i){
		if ('0'<=s[i]&&s[i]<='9'){
			c[s[i]-'0']++;
		}
	}
	for (int i=9;i>=0;--i){
		for (int j=0;j<c[i];++j){
			printf("%d",i);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
