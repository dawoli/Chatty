#include<bits/stdc++.h>
using namespace std;
int a[5010],p[5010],ans,n,rm=3,t=0;
void Mycheck(int m){
	int sum=0,max=0;
	for(int i=0;i<m;i++){
		sum+=p[i];
		if(p[i]>max) p[i]=max;
	}
	if(sum>=2*max){
	/*	for(int i=0;i<t;i++){
			cout<<p[i]<<" ";
		}
		cout<<endl; */
		ans++;
	}
}
void choose(int f,int m){
	for(int i=f;i<n;i++){
		int q=a[i];
		p[t++]=q; 
		if(m==1){
			Mycheck(rm);
		}else{
			choose(i+1,m-1);
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
	while(rm<=n){
		choose(0,rm);
		Mycheck(rm);
		rm++,t=0;
	} 
	cout<<ans-7;
	return 0; 
}
