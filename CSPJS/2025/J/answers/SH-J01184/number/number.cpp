#include<bits/stdc++.h>
using namespace std;
int hashb[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	for(auto i:s){
		if('0'<=i&&i<='9'){
			hashb[i-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<hashb[i];j++){
			printf("%d",i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
