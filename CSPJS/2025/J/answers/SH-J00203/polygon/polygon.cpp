#include<bits/stdc++.h>
using namespace std;
int n;
int a[6000];
int v[6000]={0};
long long num=0;
void f(int t,long long length,int maxl,int o){
	if(t>=3&&length>2*maxl){
		num++;
	}
	if(t==n){
		return ;
	}
	for(int i=o;i<n;i++){
		if(v[i]==0){
			v[i]=1;
			f(t+1,length+a[i],max(maxl,a[i]),i);
			v[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	f(0,0,0,0);
	cout<<num%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

