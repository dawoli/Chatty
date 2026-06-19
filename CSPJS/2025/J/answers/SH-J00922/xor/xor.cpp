#include<bits/stdc++.h>
using namespace std;
int a[233333];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	if(n==1){
		int ok;
		cin>>ok;
		if(ok==k)cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	if(n==2){
		int x,y;
		cin>>x>>y;
		if(x==k)ans++;
		if(y==k)ans++;
		if(x^y==k)ans++;
		cout<<ans<<endl;
		return 0;
	}int A=0;
	int B=1;
	if(k!=0&&k!=1)B=0;
	if(k!=0)A=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)A=1;
		if(a[i]!=1&&a[i]!=0)B=0;
	}if(!A){
		cout<<n/2<<endl;
		return 0;
	}if(B){
		
		if(k==0){
			for(int i=0;i<n;i++){
				if(a[i]==0)ans++;
				else{
					int opo=1;
					i++;
					while(a[i]!=0)i++,opo++;
					i--;
					ans+=opo/2;
				} 
			}
		}else{
			for(int i=0;i<n;i++){
				if(a[i]==1)ans++;
				else{
					int opo=1;
					i++;
					while(a[i]!=1)i++,opo++;
					i--;
					//ans+=opo/2;
					//cout<<opo/2<<' ';
				} 
			}	
		}cout<<ans<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		int now=a[i];
		if(now==k){
			ans++;
			continue;
		}
		for(int j=i+1;j<n;j++){
			now^=a[j];
			if(now==k){
				ans++;
				i=j+1;
				continue;
			}
		}
	}cout<<ans<<endl;
	return 0;
}
