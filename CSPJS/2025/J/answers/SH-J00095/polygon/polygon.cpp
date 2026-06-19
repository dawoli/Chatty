#include<bits/stdc++.h>
using namespace std;
int n,a[500005];
int MOD=998244353; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>a[1]>>a[2]>>a[3];
		int t=max(max(a[1],a[2]),a[3]);
		if(a[1]+a[2]+a[3]>2*t)cout<<1;
		else cout<<0;
		return 0;
	}
	bool flag=true; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=false;
	}
	if(flag){
		int num=0;
		for(int i=3;i<=n;i++){
			int ans=1;
			int up=min(i,n-i);
			for(int j=1;j<=up;j++){
				ans*=n-j+1;
			}
			for(int j=1;j<=up;j++){
				ans/=j;
			}
			num+=ans;
		}
		cout<<num;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	for(int k=j+1;k<=n;k++){
	if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]) )ans++;}}}
	
	for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	for(int k=j+1;k<=n;k++){
	for(int ii=k+1;ii<=n;ii++){
	if(a[i]+a[j]+a[k]+a[ii]>2*max(max(a[i],a[j]),max(a[ii],a[k])) )ans++;}}}}
	
	for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	for(int k=j+1;k<=n;k++){
	for(int ii=k+1;ii<=n;ii++){
	for(int jj=ii+1;jj<=n;jj++){
	if(a[i]+a[j]+a[k]+a[ii]+a[jj]>2*max(max(max(a[i],a[j]),max(a[ii],a[k])),a[jj]) )ans++;}}}}}
		
	for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	for(int k=j+1;k<=n;k++){
	for(int ii=k+1;ii<=n;ii++){
	for(int jj=ii+1;jj<=n;jj++){
	for(int kk=jj+1;kk<=n;kk++){
	if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]>2*max(max(max(a[i],a[j]),max(a[ii],a[k])),max(a[jj],a[kk])) )ans++;}}}}}}
	
	for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	for(int k=j+1;k<=n;k++){
	for(int ii=k+1;ii<=n;ii++){
	for(int jj=ii+1;jj<=n;jj++){
	for(int kk=jj+1;kk<=n;kk++){
	for(int iii=kk+1;iii<=n;iii++){
	if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]>2*max(max(max(a[i],a[j]),max(a[ii],a[k])),max(max(a[jj],a[kk]),a[iii])) )ans++;}}}}}}}
	
	for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	for(int k=j+1;k<=n;k++){
	for(int ii=k+1;ii<=n;ii++){
	for(int jj=ii+1;jj<=n;jj++){
	for(int kk=jj+1;kk<=n;kk++){
	for(int iii=kk+1;iii<=n;iii++){
	for(int jjj=iii+1;jjj<=n;jjj++){
	if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]+a[jjj]>2*
	max(max(max(a[i],a[j]),max(a[ii],a[k])),max(max(a[jj],a[kk]),max(a[iii],a[jjj]))) )ans++;}}}}}}}}
	
	for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	for(int k=j+1;k<=n;k++){
	for(int ii=k+1;ii<=n;ii++){
	for(int jj=ii+1;jj<=n;jj++){
	for(int kk=jj+1;kk<=n;kk++){
	for(int iii=kk+1;iii<=n;iii++){
	for(int jjj=iii+1;jjj<=n;jjj++){
	for(int kkk=jjj+1;kkk<=n;kkk++){
	if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]+a[jjj]+a[kkk]>2*
	max(max(max(max(a[i],a[j]),max(a[ii],a[k])),max(max(a[jj],a[kk]),max(a[iii],a[jjj]))),a[kkk]) )ans++;}}}}}}}}}
	
	for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	for(int k=j+1;k<=n;k++){
	for(int ii=k+1;ii<=n;ii++){
	for(int jj=ii+1;jj<=n;jj++){
	for(int kk=jj+1;kk<=n;kk++){
	for(int iii=kk+1;iii<=n;iii++){
	for(int jjj=iii+1;jjj<=n;jjj++){
	for(int kkk=jjj+1;kkk<=n;kkk++){
	for(int iiii=kkk+1;iiii<=n;iiii++){
	if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]+a[jjj]+a[kkk]+a[iiii]>2*
	max(max(max(max(a[i],a[j]),max(a[ii],a[k])),max(max(a[jj],a[kk]),max(a[iii],a[jjj]))),max(a[kkk],a[iiii])) )ans++;}}}}}}}}}}
	
	for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	for(int k=j+1;k<=n;k++){
	for(int ii=k+1;ii<=n;ii++){
	for(int jj=ii+1;jj<=n;jj++){
	for(int kk=jj+1;kk<=n;kk++){
	for(int iii=kk+1;iii<=n;iii++){
	for(int jjj=iii+1;jjj<=n;jjj++){
	for(int kkk=jjj+1;kkk<=n;kkk++){
	for(int iiii=kkk+1;iiii<=n;iiii++){
	for(int jjjj=iiii+1;jjjj<=n;jjjj++){
	if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]+a[jjj]+a[kkk]+a[iiii]+a[jjjj]>2*
	max(max(max(max(max(a[i],a[j]),max(a[ii],a[k])),max(max(a[jj],a[kk]),max(a[iii],a[jjj]))),max(a[kkk],a[iiii])),a[jjjj]) )ans++;}}}}}}}}}}}
	
	for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	for(int k=j+1;k<=n;k++){
	for(int ii=k+1;ii<=n;ii++){
	for(int jj=ii+1;jj<=n;jj++){
	for(int kk=jj+1;kk<=n;kk++){
	for(int iii=kk+1;iii<=n;iii++){
	for(int jjj=iii+1;jjj<=n;jjj++){
	for(int kkk=jjj+1;kkk<=n;kkk++){
	for(int iiii=kkk+1;iiii<=n;iiii++){
	for(int jjjj=iiii+1;jjjj<=n;jjjj++){
	for(int kkkk=jjjj+1;kkkk<=n;kkkk++){
	if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]+a[jjj]+a[kkk]+a[iiii]+a[jjjj]+a[kkkk]>2*
	max(max(max(max(max(a[i],a[j]),max(a[ii],a[k])),max(max(a[jj],a[kk]),max(a[iii],a[jjj]))),max(a[kkk],a[iiii])),max(a[jjjj],a[kkkk])) )ans++;}}}}}}}}}}}}
	
	for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	for(int k=j+1;k<=n;k++){
	for(int ii=k+1;ii<=n;ii++){
	for(int jj=ii+1;jj<=n;jj++){
	for(int kk=jj+1;kk<=n;kk++){
	for(int iii=kk+1;iii<=n;iii++){
	for(int jjj=iii+1;jjj<=n;jjj++){
	for(int kkk=jjj+1;kkk<=n;kkk++){
	for(int iiii=kkk+1;iiii<=n;iiii++){
	for(int jjjj=iiii+1;jjjj<=n;jjjj++){
	for(int kkkk=jjjj+1;kkkk<=n;kkkk++){
	for(int iiiii=kkkk+1;iiiii<=n;iiiii++){
	if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]+a[jjj]+a[kkk]+a[iiii]+a[jjjj]+a[kkkk]+a[iiiii]>2*
	max(max(max(max(max(max(a[i],a[j]),max(a[ii],a[k])),max(max(a[jj],a[kk]),max(a[iii],a[jjj]))),max(a[kkk],a[iiii])),max(a[jjjj],a[kkkk])),a[iiiii]) )ans++;}}}}}}}}}}}}}
	
	for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	for(int k=j+1;k<=n;k++){
	for(int ii=k+1;ii<=n;ii++){
	for(int jj=ii+1;jj<=n;jj++){
	for(int kk=jj+1;kk<=n;kk++){
	for(int iii=kk+1;iii<=n;iii++){
	for(int jjj=iii+1;jjj<=n;jjj++){
	for(int kkk=jjj+1;kkk<=n;kkk++){
	for(int iiii=kkk+1;iiii<=n;iiii++){
	for(int jjjj=iiii+1;jjjj<=n;jjjj++){
	for(int kkkk=jjjj+1;kkkk<=n;kkkk++){
	for(int iiiii=kkkk+1;iiiii<=n;iiiii++){
	for(int jjjjj=iiiii+1;jjjjj<=n;jjjjj++){
	if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]+a[jjj]+a[kkk]+a[iiii]+a[jjjj]+a[kkkk]+a[iiiii]+a[jjjjj]>2*
	max(max(max(max(max(max(max(a[i],a[j]),max(a[ii],a[k])),max(max(a[jj],a[kk]),max(a[iii],a[jjj])))
	,max(a[kkk],a[iiii])),max(a[jjjj],a[kkkk])),a[iiiii]),a[jjjjj]) )ans++;}}}}}}}}}}}}}}
	
	for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	for(int k=j+1;k<=n;k++){
	for(int ii=k+1;ii<=n;ii++){
	for(int jj=ii+1;jj<=n;jj++){
	for(int kk=jj+1;kk<=n;kk++){
	for(int iii=kk+1;iii<=n;iii++){
	for(int jjj=iii+1;jjj<=n;jjj++){
	for(int kkk=jjj+1;kkk<=n;kkk++){
	for(int iiii=kkk+1;iiii<=n;iiii++){
	for(int jjjj=iiii+1;jjjj<=n;jjjj++){
	for(int kkkk=jjjj+1;kkkk<=n;kkkk++){
	for(int iiiii=kkkk+1;iiiii<=n;iiiii++){
	for(int jjjjj=iiiii+1;jjjjj<=n;jjjjj++){
	for(int kkkkk=jjjjj+1;kkkkk<=n;kkkkk++){
	if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]+a[jjj]+a[kkk]+a[iiii]+a[jjjj]+a[kkkk]+a[iiiii]+a[jjjjj]+a[kkkkk]>2*
	max(max(max(max(max(max(max(max(a[i],a[j]),max(a[ii],a[k])),max(max(a[jj],a[kk]),max(a[iii],a[jjj])))
	,max(a[kkk],a[iiii])),max(a[jjjj],a[kkkk])),a[iiiii]),a[jjjjj]),a[kkkkk]) )ans++;}}}}}}}}}}}}}}}
	
	for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	for(int k=j+1;k<=n;k++){
	for(int ii=k+1;ii<=n;ii++){
	for(int jj=ii+1;jj<=n;jj++){
	for(int kk=jj+1;kk<=n;kk++){
	for(int iii=kk+1;iii<=n;iii++){
	for(int jjj=iii+1;jjj<=n;jjj++){
	for(int kkk=jjj+1;kkk<=n;kkk++){
	for(int iiii=kkk+1;iiii<=n;iiii++){
	for(int jjjj=iiii+1;jjjj<=n;jjjj++){
	for(int kkkk=jjjj+1;kkkk<=n;kkkk++){
	for(int iiiii=kkkk+1;iiiii<=n;iiiii++){
	for(int jjjjj=iiiii+1;jjjjj<=n;jjjjj++){
	for(int kkkkk=jjjjj+1;kkkkk<=n;kkkkk++){
	for(int iiiiii=kkkkk+1;iiiiii<=n;iiiiii++){
	if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]+a[jjj]+a[kkk]+a[iiii]+a[jjjj]+a[kkkk]+a[iiiii]+a[jjjjj]+a[kkkkk]+a[iiiiii]>2*
	max(max(max(max(max(max(max(max(max(a[i],a[j]),max(a[ii],a[k])),max(max(a[jj],a[kk]),max(a[iii],a[jjj])))
	,max(a[kkk],a[iiii])),max(a[jjjj],a[kkkk])),a[iiiii]),a[jjjjj]),a[kkkkk]),a[iiiiii]) )ans++;}}}}}}}}}}}}}}}}
	
	for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	for(int k=j+1;k<=n;k++){
	for(int ii=k+1;ii<=n;ii++){
	for(int jj=ii+1;jj<=n;jj++){
	for(int kk=jj+1;kk<=n;kk++){
	for(int iii=kk+1;iii<=n;iii++){
	for(int jjj=iii+1;jjj<=n;jjj++){
	for(int kkk=jjj+1;kkk<=n;kkk++){
	for(int iiii=kkk+1;iiii<=n;iiii++){
	for(int jjjj=iiii+1;jjjj<=n;jjjj++){
	for(int kkkk=jjjj+1;kkkk<=n;kkkk++){
	for(int iiiii=kkkk+1;iiiii<=n;iiiii++){
	for(int jjjjj=iiiii+1;jjjjj<=n;jjjjj++){
	for(int kkkkk=jjjjj+1;kkkkk<=n;kkkkk++){
	for(int iiiiii=kkkkk+1;iiiiii<=n;iiiiii++){
	for(int jjjjjj=iiiiii+1;jjjjjj<=n;jjjjjj++){
	if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]+a[jjj]+a[kkk]+a[iiii]+a[jjjj]+a[kkkk]+a[iiiii]+a[jjjjj]+a[kkkkk]+a[iiiiii]+a[jjjjjj]>2*
	max(max(max(max(max(max(max(max(max(max(a[i],a[j]),max(a[ii],a[k])),max(max(a[jj],a[kk]),max(a[iii],a[jjj])))
	,max(a[kkk],a[iiii])),max(a[jjjj],a[kkkk])),a[iiiii]),a[jjjjj]),a[kkkkk]),a[iiiiii]),a[jjjjjj]) )ans++;}}}}}}}}}}}}}}}}}
	
	for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	for(int k=j+1;k<=n;k++){
	for(int ii=k+1;ii<=n;ii++){
	for(int jj=ii+1;jj<=n;jj++){
	for(int kk=jj+1;kk<=n;kk++){
	for(int iii=kk+1;iii<=n;iii++){
	for(int jjj=iii+1;jjj<=n;jjj++){
	for(int kkk=jjj+1;kkk<=n;kkk++){
	for(int iiii=kkk+1;iiii<=n;iiii++){
	for(int jjjj=iiii+1;jjjj<=n;jjjj++){
	for(int kkkk=jjjj+1;kkkk<=n;kkkk++){
	for(int iiiii=kkkk+1;iiiii<=n;iiiii++){
	for(int jjjjj=iiiii+1;jjjjj<=n;jjjjj++){
	for(int kkkkk=jjjjj+1;kkkkk<=n;kkkkk++){
	for(int iiiiii=kkkkk+1;iiiiii<=n;iiiiii++){
	for(int jjjjjj=iiiiii+1;jjjjjj<=n;jjjjjj++){
	for(int kkkkkk=jjjjjj+1;kkkkkk<=n;kkkkkk++){
	if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]+a[jjj]+a[kkk]
	+a[iiii]+a[jjjj]+a[kkkk]+a[iiiii]+a[jjjjj]+a[kkkkk]+a[iiiiii]+a[jjjjjj]+a[kkkkkk]>2*
	max(max(max(max(max(max(max(max(max(max(max(a[i],a[j]),max(a[ii],a[k])),max(max(a[jj],a[kk]),max(a[iii],a[jjj])))
	,max(a[kkk],a[iiii])),max(a[jjjj],a[kkkk])),a[iiiii]),a[jjjjj]),a[kkkkk]),a[iiiiii]),a[jjjjjj]),a[kkkkkk]) )ans++;}}}}}}}}}}}}}}}}}}
	
	for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	for(int k=j+1;k<=n;k++){
	for(int ii=k+1;ii<=n;ii++){
	for(int jj=ii+1;jj<=n;jj++){
	for(int kk=jj+1;kk<=n;kk++){
	for(int iii=kk+1;iii<=n;iii++){
	for(int jjj=iii+1;jjj<=n;jjj++){
	for(int kkk=jjj+1;kkk<=n;kkk++){
	for(int iiii=kkk+1;iiii<=n;iiii++){
	for(int jjjj=iiii+1;jjjj<=n;jjjj++){
	for(int kkkk=jjjj+1;kkkk<=n;kkkk++){
	for(int iiiii=kkkk+1;iiiii<=n;iiiii++){
	for(int jjjjj=iiiii+1;jjjjj<=n;jjjjj++){
	for(int kkkkk=jjjjj+1;kkkkk<=n;kkkkk++){
	for(int iiiiii=kkkkk+1;iiiiii<=n;iiiiii++){
	for(int jjjjjj=iiiiii+1;jjjjjj<=n;jjjjjj++){
	for(int kkkkkk=jjjjjj+1;kkkkkk<=n;kkkkkk++){
	for(int iiiiiii=kkkkkk+1;iiiiiii<=n;iiiiiii++){
	if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]+a[jjj]+a[kkk]
	+a[iiii]+a[jjjj]+a[kkkk]+a[iiiii]+a[jjjjj]+a[kkkkk]+a[iiiiii]+a[jjjjjj]+a[kkkkkk]+a[iiiiiii]>2*
	max(max(max(max(max(max(max(max(max(max(max(max(a[i],a[j]),max(a[ii],a[k])),max(max(a[jj],a[kk]),max(a[iii],a[jjj])))
	,max(a[kkk],a[iiii])),max(a[jjjj],a[kkkk])),a[iiiii]),a[jjjjj]),
	a[kkkkk]),a[iiiiii]),a[jjjjjj]),a[kkkkkk]),a[iiiiiii]) )ans++;}}}}}}}}}}}}}}}}}}}
	
	for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	for(int k=j+1;k<=n;k++){
	for(int ii=k+1;ii<=n;ii++){
	for(int jj=ii+1;jj<=n;jj++){
	for(int kk=jj+1;kk<=n;kk++){
	for(int iii=kk+1;iii<=n;iii++){
	for(int jjj=iii+1;jjj<=n;jjj++){
	for(int kkk=jjj+1;kkk<=n;kkk++){
	for(int iiii=kkk+1;iiii<=n;iiii++){
	for(int jjjj=iiii+1;jjjj<=n;jjjj++){
	for(int kkkk=jjjj+1;kkkk<=n;kkkk++){
	for(int iiiii=kkkk+1;iiiii<=n;iiiii++){
	for(int jjjjj=iiiii+1;jjjjj<=n;jjjjj++){
	for(int kkkkk=jjjjj+1;kkkkk<=n;kkkkk++){
	for(int iiiiii=kkkkk+1;iiiiii<=n;iiiiii++){
	for(int jjjjjj=iiiiii+1;jjjjjj<=n;jjjjjj++){
	for(int kkkkkk=jjjjjj+1;kkkkkk<=n;kkkkkk++){
	for(int iiiiiii=kkkkkk+1;iiiiiii<=n;iiiiiii++){
	for(int jjjjjjj=iiiiiii+1;jjjjjjj<=n;jjjjjjj++){
	if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]+a[jjj]+a[kkk]
	+a[iiii]+a[jjjj]+a[kkkk]+a[iiiii]+a[jjjjj]+a[kkkkk]+a[iiiiii]+a[jjjjjj]+a[kkkkkk]+a[iiiiiii]+a[jjjjjjj]>2*
	max(max(max(max(max(max(max(max(max(max(max(max(max(a[i],a[j]),max(a[ii],a[k])),max(max(a[jj],a[kk]),max(a[iii],a[jjj])))
	,max(a[kkk],a[iiii])),max(a[jjjj],a[kkkk])),a[iiiii]),a[jjjjj]),
	a[kkkkk]),a[iiiiii]),a[jjjjjj]),a[kkkkkk]),a[iiiiiii]),a[jjjjjjj]) )ans++;}}}}}}}}}}}}}}}}}}}}
	cout<<ans%MOD;
	return 0;
}
