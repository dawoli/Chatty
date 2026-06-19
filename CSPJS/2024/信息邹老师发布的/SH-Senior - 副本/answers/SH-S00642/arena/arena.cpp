#include<iostream>
using namespace std;
const int N=1e5+10;
int n,m,T;
int a[N],c[N],a2[4],at[N];
string dl[N];
int p(int a,int n){
	int tmp=1;
	for(int i=0;i<n;i++){
		tmp=tmp*a;
	}
	return tmp;
}
int leitai(int r,int x,int y,int b){
	if(x!=-1 and y!=-1){
		if(b){
			if(y>=r)return 1;
			else return 0;
		}
		else{
			if(x>=r)return 0;
			else return 1;
		}
	}
	else{
		return 2;
	}
}
int bisai(int sum,int a[]){
	int att[N],tmp[N];
	for(int i=1;i<=sum;i++){
		att[i]=a[i];
	}
	int n=0;bool erbei=0;
	while(p(2,n)<=sum){
		n++;
	}
	while(p(2,n)>sum){
		sum+=1;
		att[sum]=-1;
	}
	int r=1;
	while(true){
		for(int i=1;i<=n;i=i+2){
			if(leitai(r,at)!=2){
				
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>c[i];
	}
	int x=0;
	while(p(2,x)<n){
		cin>>dl[x];
		x++;
	}
	cin>>T;
	for(int i=0;i<T;i++){
		for(int j=0;j<4;j++){
			cin>>a2[j];
		}
		for(int i=1;i<=n;i++){
			at[i]=a[i]^a2[i%4];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			a=ans^bisai(a2[i],at);
		}
	}
	return 0;
}
