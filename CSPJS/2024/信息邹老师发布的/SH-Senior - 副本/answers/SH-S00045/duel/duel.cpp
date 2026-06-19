#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n,a[N],flag[N];
long long maxn=-1,minn=1e9;
long long cnt;
int main(){
	freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long c;
		cin>>c;
		a[c]++;
		flag[c]++;
		maxn=max(maxn,c);
		minn=min(minn,c); 
	}
	long long x=minn,y=minn+1;
	while(y<=maxn){ 
		while(a[y]==0){
			y++;
		}
		if(a[x]<a[y]){
			cnt+=a[x];
			a[x]=0;
			while(a[x]==0){
				x++;
			}
			if(x==y){
				y++;
			}
		}else if(a[x]==a[y]){				
			cnt+=a[x];
			a[x]=0;
			x=y;
			while(a[x]==0){
				x++;
			}	
			y=x;
			y++;		
		}else{
			if(flag[y]!=0){
				cnt+=a[y];
				flag[y]-=a[x];
				a[x]-=a[y];	
			}
			y++;			
		}
	}
	cout<<n-cnt;
}

