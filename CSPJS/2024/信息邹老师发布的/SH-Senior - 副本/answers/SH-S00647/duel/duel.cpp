#include<bits/stdc++.h>
using namespace std;
long long a[100010]={0};
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	long long n,r[100010],cnt=0;
	cin>>n; 
	for(long long i=0;i<n;i++){
		cin>>r[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=i;j<n;j++){
			if(r[j]<r[i]){
				long long a=r[j];
				r[j]=r[i];
				r[i]=a;
			}
		}
	}
	for(long long i=0;i<n;i++){
		for(long long j=i+1;j<n;j++){
			if(a[j]==0&&a[i]!=-1){
				if(r[i]<r[j]){
					a[i]=-1;
					a[j]=1;
					cnt++;
				}
			}	
		}
	}
	
	cout<<n-cnt;
	return 0;
} 
