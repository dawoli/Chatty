#include<bits/stdc++.h>
using namespace std;
int c[11]={0,0,0,0,0,0,0,0,0,0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string a;
	cin>>a;
	int n=a.size();
	a="!"+a;
	for(int i=1;i<=n;i++){
		if('0'<=a[i]&&a[i]<='9'){
			int b=a[i]-'0';
			c[b]++;
			//cout<<b;
		}
	}
	//for(int i=0;i<=9;i++)cout<<c[i]<<" ";
	for(int i=9;i>=0;i--){
		for(int j=0;j<c[i];j++){
			cout<<i;
		}
	}
} 
