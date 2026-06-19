#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,q,r,c;
int from[100002],S[200001];
bool valid(int r,int lp,int ln){// last p,last number
	if(r==0) return ln==c;
	for(int p=1;p<=n;p++)if(p!=lp){// p:ren2
		int s=from[p],t=from[p+1]-1;
		for(int i=s;i<=t;i++)if(S[i]==ln)// i:(ci2)'s id
			for(int len=2;len<=k;len++)
				if( i+len-1 <= from[p+1]-1 && valid( r-1,p,S[i+len-1] ) )
					return 1;
	}
	return 0;
}
bool vd(){
	for(int i=1;i<=n;i++)
		for(int j=from[i];j<=from[i+1]-2;j++)
			if(S[j]==1 && S[j+1]==1) return 1;
	return 0;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
	cin>>n>>k>>q;
	from[1]=1;
	for(int i=1;i<=n;i++){
		int l;cin>>l;from[i+1]=from[i]+l;
		for(int k=1;k<=l;k++)
			cin>>S[from[i]+k-1];
	}
	for(int iq=1;iq<=q;iq++){
		cin>>r>>c;
		if(r==1 && c==1)
			if(vd()) cout<<1<<endl;
			else cout<<0<<endl;
		else
			if(valid(r,0,1)) cout<<1<<endl;
			else cout<<0<<endl;
	}
	}
	return 0;
}

