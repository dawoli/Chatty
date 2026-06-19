#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int x[10],i;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000001];
	cin>>a;
	int l=strlen(a);
	for(int j=0;j<l;j++){
		if('a'<=a[j] && 'z'>=a[j]){
			continue;
		}
		else{
			x[int(a[j])-'0']++;
			i++;
		}
	}
	for(int k=9;k>=0;k--){
		if(x[k]>0){
			while(x[k]--){
				cout<<k;
			}
		}
	}
	return 0;
} 
