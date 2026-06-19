#include<bits/stdc++.h>
using namespace std;
int n,num=1,cnt=0,ans=0;
int a[100005]={};
int v[100005]={};
int v1[100005]={};
int v2[100005]={};
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	v[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){	
			v1[num]=i;
			num++;
		}
		v[num]++;
	}
	for(int i=num;i>=1;i--){
		v2[i]=v[i]+v2[i+1];
	}

	for(int i=2;i<=num;i++){
		if(v[i-1]<=v2[i]-cnt){
			cnt=v[i-1]-v[i];
			ans+=v[i-1];
		}
		else{
			ans+=v2[i]-cnt;
			break;
		}
	}
	cout<<n-ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
