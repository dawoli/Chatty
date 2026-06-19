#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n,r[N]; 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	int st=0,b=0,bb=0,be=0,ans=0;
	for(int i=1;i<=n+1;i++){
		if(st!=r[i]){
			st=r[i];
			if(be==0&&bb==0){
				bb=b;
				b=1;
				continue;
			}
			be=b;
			if(bb<=be){
				ans+=bb;
				bb=be;
			}else{
				ans+=be;
			}
			b=1;
		}else{
			b++;
		}
	}
	cout<<n-ans<<"\n";
	return 0;
} 
