#include <bits/stdc++.h>
using namespace std;
char c[1000005];
int num[11];	
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c;
	int j=0;
	for(int i=0;i<strlen(c);i++){
		if(c[i]>='0'&&c[i]<='9'){
			num[c[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<num[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
