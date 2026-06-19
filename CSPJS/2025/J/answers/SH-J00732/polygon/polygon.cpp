#include <bits/stdc++.h>
using namespace std;
int n,cnt,cntt,cnttt,cntttt,cnttttt,cntttttt,ans,anss,ansss,anssss,ansssss,anssssss;
int a[5010];
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	
	if(n==3){
		for(int i=1; i<=n; i++){
			cin>>a[i];
			cnt+=a[i];
		}
		int res=0;
		for(int i=1; i<=n; i++){
			res=max(res,a[i]);
		}
		if(cnt>2*res) cout<<1;
		else cout<<0;
	}
	
	if(n==4){
		int nnn=0;
		for(int i=1; i<=n; i++){
			cin>>a[i];
		}
		cnt=a[1]+a[2]+a[3];
		cntt=a[1]+a[3]+a[4];
		cnttt=a[1]+a[2]+a[4];
		cntttt=a[2]+a[3]+a[4];
		cnttttt=a[1]+a[2]+a[3]+a[4];
		ans=max(max(a[1],a[2]),a[3]);
		anss=max(max(a[1],a[3]),a[4]);
		ansss=max(max(a[1],a[2]),a[4]);
		anssss=max(max(a[2],a[3]),a[4]);
		ansssss=max(max(max(a[1],a[2]),a[3]),a[4]);
		if(cnt>2*ans) nnn++;
		if(cntt>2*anss) nnn++;
		if(cnttt>2*ansss) nnn++;
		if(cntttt>2*anssss) nnn++;
		if(cnttttt>2*ansssss) nnn++;
		cout<<nnn;
	}else{
		int mmm;
		for(int i=3; i<=n; i++){
			mmm=0;
			int xxx,yyy;
			for(int j=1; j<=i; j++){
				xxx*=j;
			}
			for(int q=n; q>n-i; q--){
				yyy*=q;
			} 
			mmm=mmm+yyy/xxx;
		}
		cout<<mmm;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
