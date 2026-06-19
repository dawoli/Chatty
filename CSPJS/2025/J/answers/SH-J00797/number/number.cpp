#include<bits/stdc++.h>
using namespace std;
string s="";int a[10]={0,0,0,0,0,0,0,0,0,0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto c:s){
		if('0'<=c&&c<='9'){
			a[c-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
