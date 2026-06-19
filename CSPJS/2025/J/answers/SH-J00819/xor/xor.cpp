#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	if(n==1){
		int a;
		cin>>a;
		if(a==k)cout<<1;
		else cout<<0;
		return 0;
	}
	if(n==2){
		int a,b;
		cin>>a>>b;
		int c=a xor b;
		cout<<(a==k)+(b==k)+(c==k);
		return 0;
	}
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		int d=a xor b,e=b xor c,g=a xor b xor c;
		cout<<(a==k)+(b==k)+(c==k)+(d==k)+(g==k)+(e==k);
		return 0;
	}
	if(n==4){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int h=a xor b,e=b xor c,tt=c xor d,g=a xor b xor c,l=b xor c xor d,p=a xor b xor c xor d;
		cout<<(a==k)+(b==k)+(c==k)+(d==k)+(g==k)+(h==k)+(tt==k)+(l==k)+(p==k);
		return 0;
	}
	return 0;
}
