#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int f=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-48>=0 && s[i]-48<=9) a[s[i]-'0']++;
	}
	for(int i=9;i>=1;i--){
		for(int j=1;j<=a[i];j++){
				if(a[i]>0){
				printf("%d",i);
				f=1;
				}
		}
	}
	if(f==0) cout<<'0';
	if(f==1){
		for(int j=1;j<=a[0];j++){
			if(a[0]>0){
				cout<<'0';
			}
		}
	}
	return 0;
}
