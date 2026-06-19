#include<bits/stdc++.h>
using namespace std;
int a[500015];
void init(){
	int n,k;
	int cnt=0;
	long long ans=0;
	cin>>n>>k;
	int f=0;//判断是否为特殊性质A 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			f--;
			cnt++;
		}
		if(a[i]!=1&&a[i]!=0){
			f+=100;
		}		
	}
	if(k==0){
		cout<<cnt;
		return;
	}
	if(f==0){//A性质 
		if(k==1){
			cout<<n;
			return;
		}
	}
	if(f<0){//B性质 
		if(k==0){
			cout<<cnt;
			return;
		}
		if(k==1){
			cout<<n-cnt;
			return;	
		}
	}
	int r=0;
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]%2==a[j]%2){
				cnt=1;
				while(a[j]&&a[i]){
					if(a[j]%2==a[i]%2){
						r+=cnt*2;
					}
			    }	
			}
			if(r==k)ans++;
		}
	}
	cout<<ans/2;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	init();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
