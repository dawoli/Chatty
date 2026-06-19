#include<bits/stdc++.h>
using namespace std;
int n,k,l,ans;
int a[500010],c[500010],x[500010];
string erji(int a){
	string s;
	char c;
	for(int i=20;i>=0;i--){
		int w=pow(2,i);
		if(a>=w){
		a-=w;c='1';
		}else c='0';
		
		s+=c;
	}
	return s;
}
int shij(string s){
	
	int sum=0;
	for(int i=0;i<=20;i++){
		int w=pow(2,20-i);
		if(s[i]=='1')sum+=w;
	}
	return sum;
}
int cor(int a,int b){
	string sa=erji(a);
	string sb=erji(b);
	string sc;
	char c;
	for(int i=0;i<=20;i++){
		if(sa[i]==sb[i]){
			c='0';
		}else c='1';
		sc+=c;
	}
	return shij(sc);
}
int main(){
	freopen("r","xor.in",stdin);
	freopen("w","xor.out",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=-1;
	}
	for(int i=1;i<=n;i++){
		c[i]=a[i];
		for(int j=1;j<i;j++){
			if(x[j]==-1)c[j]=cor(c[j],c[i]);
			if(x[j]==-1&&c[j]==k)x[j]=i;
		}
		if(c[i]==k)x[i]=i;
	}
	for(int i=1;i<=n;i++){
		if((x[i]>=0)&&(i>l)){
			for(int j=i;j<=x[i];j++){
				if((x[j]>=0)&&(x[j]<x[i]) ){l=j-1;break;}
			}
			l=x[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
