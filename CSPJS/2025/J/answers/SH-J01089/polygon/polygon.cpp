#include<iostream>
#include<cstdio>
using namespace std;
int n,a[5005];
bool b[5005];
long long num=0;
int ans(int x,int y){
	if(x<=n){
		b[x]=0;
		ans(x+1,y);
		b[x]=1;
		ans(x+1,y+1);
	}
	else{
		int sum=0,max=0;
		if(y>=3){
			for(int i=1;i<=n;i++){
				if(b[i]){
					if(a[i]>max) max=a[i];
					sum+=a[i];
				}
			}
			if(sum>(2*max)) num++;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	ans(1,0);
	cout<<num;
}
