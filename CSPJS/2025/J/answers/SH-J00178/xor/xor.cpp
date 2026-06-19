#include<bits/stdc++.h>
using namespace std;
const int N=500009;
int n,k,a[N],prexor[N],c[N];
void input(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
}
bool A(){
	for(int i=1;i<=n;i++)if(a[i]!=1)return false;
	return true;
}
void solveA(){
	if(k==0)cout<<n/2;
	else if(k==1)cout<<n;
	else cout<<0;
}
bool B(){
	for(int i=1;i<=n;i++)if(a[i]!=1&&a[i]!=0)return false;
	return true;
}
void solveB(){
	if(k==0){
		int ans=0,c1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
				if(c1)ans+=c1/2,c1=0;
			}
			if(a[i]==1)c1++;
		}
		cout<<ans;
	}
	else if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++)
			if(a[i]==1)ans++;
		cout<<ans;
	}
	else cout<<0;
}
bool C(){
	for(int i=1;i<=n;i++)if(a[i]>255)return false;
	return true;
}
void solveC(){
	if(k==0){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			else{
				c[a[i]]++;
				if(a[i-1]!=a[i])ans+=c[a[i-1]]/2,c[a[i-1]]=0;
			}
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++){
			if(a[i]==0||(a[i-1]==a[i])&&(a[i]==a[i+1]))continue;
			
		}
	}
}
void build_pre(){
	prexor[1]=a[1];
	for(int i=2;i<=n;i++)prexor[i]=prexor[i-1]^a[i];
}
int xor_sum(int l,int r){
	return (prexor[r]^prexor[l-1]);
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	input();
	if(A())solveA();
	else if(B())solveB(); //25 
	else if(C())solveC();
	return 0;
}
