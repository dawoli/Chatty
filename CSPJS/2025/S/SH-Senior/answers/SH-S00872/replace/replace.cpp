#include<bits/stdc++.h>
using namespace std;
const int P=131;
int n,q;
string x;
long long s1[200005],s2[200005],w[5000005],p[5000005],u[5000005],I,J;
void N(){
	p[0]=1;
	for(int i=1;i<=5000005;++i)
		p[i]=P*p[i-1];
}
long long Hash(string x,int choose){
	long long ans=x[0]-96;
	if(choose==1) w[0]=ans;
	if(choose==2) u[0]=ans;
	for(int i = 1;i<x.size();++i){
		ans+=(x[i]-96)*p[i];
		if(choose ==1)
		w[i]=ans;
		if(choose ==2)
		u[i]=ans;
	}
	return ans;
}
long long dif1(string x,string y){
	int i=0,j=x.size()-1;
	while(x[i]==y[i]) i++;
	while(x[j]==y[j]) j--;
	if(i==0) return w[j];
	return (w[j]-w[i-1])/p[i];
}
long long dif2(string x,string y){
	int i=0,j=x.size()-1;
	while(x[i]==y[i]) i++;
	while(x[j]==y[j]) j--;
	I=i;J=j;
	if(i==0) return u[j];
	return u[j]-u[i-1];
}
int main(){
	N();
	cin>>n>>q;
	int maxn=0;
	for(int i = 1;i<=n;++i){
		string x1,x2;
		cin>>x1>>x2;
		s1[i]=Hash(x1,0);
		s2[i]=Hash(x2,0);
		maxn=max(maxn,x1.size());
	}
	for(int i = 1;i<=q;++i){
		long long ans = 0;
		string t1,string t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0;
			break;
		}
		Hash(t1,1);Hash(t2,2);
		long long p1=dif1(t1);
		long long p2=dif2(t2);
		for(int j =0 =;j<=(maxn-J+I)&&j<=t1.size()-J;++j){
			for(int k = 0;k<=(maxn-J=i)&&k<=I;++k)
		}
	}
	return 0;
}
