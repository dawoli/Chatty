#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	while(cin>>c){
		if(c<='9'&&c>='0'){
			a[c-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]--) cout<<i;
	}
	return 0;
}
 
