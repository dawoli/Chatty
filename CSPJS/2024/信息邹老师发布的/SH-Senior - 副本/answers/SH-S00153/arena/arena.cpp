#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[100009],c[100009],k,T,a1[100009],A[100009],vst[100009];
string p[100009];
int ls(ll t){
	int s=1,i=0;
	while(1){
		s*=2;
		i++;
		if(s>=t)
			return i;
	}
}
int pan(int m,int fu){
	for(int i=m;i<=m+fu;i++)
		if(vst[i]==0)
			return i;
}
void BF(int t,int R,int G,int i,int fu){
	if(t==1)
		return ;
	if(i==t)
		BF(t/2,R+1,1,pan(1,fu),fu*2);
	if((p[R][G]==0&&a1[i]>=R)||(p[R][G]==1&&a1[pan(i+1,fu)]<R)){
		vst[pan(i+1,fu)]=1;
		BF(t,R,G+1,pan(i+fu,i+fu+fu),fu);		
	}
	else{
		vst[i]=1;
		BF(t,R,G+1,pan(i+fu,i+fu+fu),fu);			
	}
}
int search(int t){
	for(int i=1;i<=t;i++){
		if(vst[i]==0)
			return i;
	}
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>c[i];
	k=ls(n);
	for(int i=1;i<=k;i++)
		cin>>p[i];
	cin>>T;
	for(int hh=1;hh<=T;hh++){
		int X[3];
		ll sum=0;
		cin>>X[0]>>X[1]>>X[2]>>X[3];
		for(int i=1;i<=n;i++)
			a1[i]=a[i]^X[i%4];
		for(int i=1;i<=m;i++){
			for(int j=1;j<=c[i];j++)
				vst[j]=0;
			BF(c[i],1,1,1,1);
			A[i]=search(c[i]);			
		}
		sum=1*A[1];
		for(int i=2;i<=m;i++)		
			sum=sum^(i*A[i]);
		cout<<sum;
	}
	return 0;
} 
