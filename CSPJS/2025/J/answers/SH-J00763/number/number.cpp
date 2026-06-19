#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[20]={0};
	string s;
	cin>>s;
	for(auto c : s){
		if(c>='0' && c<='9') a[c-'0']++;
	}
	for(int i = 9;i>=0;i--){
		for(int j = 1;j<=a[i];j++) printf("%d",i);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
