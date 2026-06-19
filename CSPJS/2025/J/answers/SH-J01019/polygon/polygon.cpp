#include<bits/stdc++.h>
using namespace std;

int mod=998244353;
const int N=5e5+1;
int l[N];
int cnt=0;
int n;
void choose(int pos,int X,int MAX,int count){
	if(count==0){
		if(X>2*MAX) cnt=(cnt+1)%mod;
		return;
	}
	if(pos>n) return ;
	choose(pos+1,X,MAX,count);
	X+=l[pos];
	MAX=max(MAX,l[pos]);

	choose(pos+1,X,MAX,count-1);
	
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}

	for(int m=3;m<=n;m++){  //枚举个数 
		int x=0,Max=-1;
		for(int j=1;j<=n;j++){//枚举位置 
            choose(j,x,Max,m);
		}
	}
	cout<<cnt;
	return 0;
}
