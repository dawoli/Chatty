#include<bits/stdc++.h>
using namespace std;
long long n,ans,k[100005],m,a[100005],k2[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	m=1;
	for(int i=0;i<n;i++){
		if(a[i]!=a[i+1]){
			k[m++]++;k2[m]++;
		}
		else{
			k[m]++;k2[m]++;
		}
	}
	m--;
	if(m==1){
		cout<<k[1];
		return 0;
	}
	if(m==2){
		if(k[1]>k[2]){
			cout<<k[1];
		}
		else{
			cout<<k[2];
		}
		return 0;
	}
	for(int i=1;i<m;i++){
		for(int j=i+1;j<=m;j++){
			if(k[i]==0){
				if(i==m-1){
					continue;
				}
				else{
					i++;
					j=i+1;
				}
			}
			if(k2[j]==0){
				if(j==m) continue;
				else j++; 
			}
			if(k[i]<k2[j]){
				n-=k[i];
				k[i]=0;
				k2[j]-=k[i];
			}
			else{
				n-=k2[j];
				k[i]-=k2[j];
				k2[j]=0;
			}
		}
	}
	cout<<n;
	return 0;
}
