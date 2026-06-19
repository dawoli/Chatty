#include<bits/stdc++.h>
using namespace std;
char a[1000];
char b[1000];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>s;
		a[i]=s[0];
		b[i]=s[1];
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>i;j--){
			if(a[j]==a[i] and b[j]==b[i] and (a[j+1]!=a[i] or b[j+1]!=b[i]))ans++;
		}
	}
	int y=n-ans;
	cout<<52-y;
}
