#include<bits/stdc++.h>
using namespace std;
long long num=0;
int n,m,c[505]={},f=1,n0=0;
string s;
int fu(int d,int p,int die,int a[],int nn){
	if(d==n&&p>=m){
		return 1;
	}
	else if(d==n){
		return 0;
	}
	if(nn!=-1){
		if(s[d]=='1'&&c[nn]>die){
			p+=1;
		}
		else{
			die+=1;
		}
		d+=1;
	}
	long long ans=0;
	for(int i=0;i<n;i+=1){
		if(a[i]){
			continue;
		}
		a[i]=1;
		ans+=fu(d,p,die,a,i);
		a[i]=0;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i+=1){
		cin>>c[i];
		if(c[i]==0){
			n0+=1;
		}
		if(s[i]=='0'){
			f=0;
		}
	}
	if(m>n-n0){
		cout<<"0\n";
	}
	else if(f){
		num=1;
		for(int i=1;i<=n;i+=1){
			num=(num*i)%998244353;
		}
		cout<<num<<"\n";
	}
	else if(m==n){
		cout<<"0\n";
	}
	else{
		int a[505]={};
		cout<<fu(0,0,0,a,-1)<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
