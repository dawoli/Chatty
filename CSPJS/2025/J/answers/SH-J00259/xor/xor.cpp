#include<bits/stdc++.h>
using namespace std;
int ch[21]={},zh[21]={};
int n,k,a[100][20]={},c=1,al;
int fin(int no,int r[21],int ans){
	if(no>n+1){
		return ans;
	}
	if(ch[0]==r[0]){
		bool che=true;
		for(int i=1;i<=ch[0];i++){
			if(ch[i]!=r[i]) che=0;
		}
		if(che) {
			ans++;
			r[0]=0;
		}
	}
	if(r[0]){
		r[0]=max(r[0],a[no][0]);
		for(int i=1;i<=r[0];i++){
			r[i]=(r[i]+a[no][i])%2;
		}
		
		if(r[r[0]]==0){
			for(int i=r[0];i>=1;i--){
				if(r[i]!=0) {
					r[0]=i;
					break;
				}
			}
		}
		if(ch[0]==r[0]){
		bool che=true;
		for(int i=1;i<=ch[0];i++){
			if(ch[i]!=r[i]) che=0;
		}
		if(che) {
			ans++;
			r[0]=0;
		}
	}
		return fin(no+1,r,ans);
	}else{
		r[0]=max(r[0],a[no][0]);
		for(int i=1;i<=r[0];i++){
			r[i]=a[no][i];
		}
		return max(fin(no+1,zh,ans),fin(no+1,r,ans));
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	while(k){
		ch[c]=k%2;
		c++;
		k=k/2;
		ch[0]++;
	}
	int in,chaju=0,er=0;
	for(int i=1;i<=n;i++){
		cin>>in;
		if(i==1&&in==k) er++;
		c=1;
		while(in){
			a[i-chaju][c]=in%2;
			c++;
			in=in/2;
			a[i-chaju][0]++;
		}
	}
	n=n-chaju;
	cout<<fin(1,zh,er);
	
	return 0;
}
