#include<bits/stdc++.h>
using namespace std;
int a[100100];
int b[10010][2];
int xxor(int a,int b){
	string ab="";
	while(a>0||b>0){
		if((a%2==0&&b%2!=0)||(b%2==0&&a%2!=0)){
			ab+='1';
		}
		else{
			ab+='0';
		}
		a>>=1;
		b>>=1;
	}
	int ans=0;
	int x=1;
	for(int j=0;j<ab.size();j++){
		if(ab[j]=='1'){
			ans+=x;
		}
		x*=2;
	}
	return ans;
}
int sum(int l,int r,int xornum){
	int sum=a[l];
	for(int i=l+1;i<r;i++){
		sum=xxor(sum,a[i]);
	}
	if(sum==xornum){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,x=0,chong=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(sum(i,j,k)==1){
				b[x][1]=i;
				b[x][2]=j;
				x++;
				ans++;
			}
		}
	}
	for(int i=0;i<=x;i++){
		for(int j=0;j<=x;j++){
			if((b[i][1]>b[j][1]&&b[i][1]<b[j][2])||(b[j][1]>b[i][1]&&b[j][1]<b[i][2])||(b[i][2]>b[j][1]&&b[i][2]<b[j][2])||(b[j][2]>b[i][1]&&b[j][2]<b[i][2])){
				chong++;
			}
		}
	}
	chong/=2;
	cout<<ans-chong;
	return 0;
} 
