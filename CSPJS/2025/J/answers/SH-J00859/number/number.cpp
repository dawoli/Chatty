#include<iostream>
using namespace std;
string s,ans;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size()-1;
	for(int i=0;i<=l;i++){
		if(s[i]-48>=0&&s[i]-48<=9){
			a[s[i]-48]++;
		}
	}
	for(int j=9;j>=0;j--){
		for(int k=a[j];k>0;k--){
			ans=ans+char(j+48);
		}
	}
	cout<<ans;
	return 0;
}
