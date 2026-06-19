#include<bits/stdc++.h>
using namespace std;

int n,ans,a[100001],c[100000],b[100001];

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	
	int a1=0,a2=0,f=0;
	for(int i=1;i<=n;i++){
		if(a[i]>2)f=1;
		if(a[i]==1)a1++;
		if(a[i]==2)a2++;
		c[a[i]]++;
	}
	if(f==0){
		if(a2>=a1){
			cout<<a2;
			return 0;
		}else{
			cout<<n-a2;
			return 0;
		}
	}
	
	int ans,s,j=1;
	for(int i=100000;i>=1;i--){
		if(c[i]!=0){b[j]=i;j++;}
	}
	j=1;
	ans=c[b[j]];
	while(b[j]>0){
		if(c[b[j]]<=c[b[j+1]])ans+=(c[b[j+1]]-c[b[j]]);
		j++;
	}
	cout<<ans;
	return 0;
}
