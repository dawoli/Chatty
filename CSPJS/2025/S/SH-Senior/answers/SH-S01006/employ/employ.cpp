#include<bits/stdc++.h>
 using namespace std;
 const int Mod=988244353;
 int n,m,a[505],cnt;
  bool cmp(int x,int y){
 	return x<y;
 }
 int main(){
 	freopen("employ.in","r",stdin);
 	freopen("employ.out","r",stdin);
 	cin>>n>>m;
 	int fir1=0;
 	string s;
 	cin>>s;
 	int l=s.length();
 	bool flag=1;
	for(int i=0;i<l;i++){
		if(flag&&m==1) {
			fir1=i+1;
			flag=0; 
		}
 		if(s[i]=='1') cnt++;
	 } 
	for(int i=1;i<=n;i++){
 		cin>>a[i];
	 } 	 
	 sort(a+1,a+1+n);	
	if(cnt<m) {
		cout<<0;
		return 0;	
	}
 	if(m==1){	
 	 	int f=0;
 		for(int i=1;i<=n;i++){
 			if(a[i]>=fir1){
 				f=i;
 		 		break;
		  	}

	 	} if(f==0){
	 		cout<<0;
		  	return 0;
		 }		  	
	 	cout<<f<<endl;
		unsigned long long ans=1,cnt=1;	
		for(int i=n;i>=n-f+2;i--){
			ans*=i;
			ans%=Mod;
		}	if(ans==1) ans=0;
		for(int i=n;i>=n-f+2;i++){
			cnt*=i;
			cnt%=Mod;
		}
		if(cnt!=1) ans+=cnt;
		ans%=Mod;
		cout<<ans;	
		return 0;
	 }	
	 if(m==n){
		for(int i=1;i<=n;i++){
 			if(a[i]<i){
 		 		cout<<0;
 		 		return 0;
		  	}
		  	cout<<1;
	 	} 	
	 	return 0;
	}
	unsigned long long ans=1;
	for(int i=cnt;i>=cnt-m+1;i--){
		ans*=i;
		ans%=Mod;
	}cout<<ans;
	return 0;
 }
