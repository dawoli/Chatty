#include<bits/stdc++.h>
using namespace std;
char a[100000005];
int k[15];
int idx;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		k[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<k[i];j++){
			cout<<i;
		}
	}
	return 0;
}
