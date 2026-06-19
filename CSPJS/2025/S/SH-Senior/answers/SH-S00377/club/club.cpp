#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int a,b,c,fise[N],x[N],y[N],z[N],tx,ty,tz;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	int n;
	while(T--){
		cin>>n;
		tx=ty=tz=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			ans+=max(a,max(b,c)),fise[i]=2*max(a,max(b,c))+min(a,min(b,c))-a-b-c;
			if(a>=b&&a>=c) tx++,x[tx]=a-max(b,c);
			else if(b>=a&&b>=c) ty++,y[ty]=b-max(c,a);
			else tz++,z[tz]=c-max(a,b);
		}
		if(tx>=ty&&tx>=tz){
			sort(x+1,x+tx+1);
			for(int i=1;i<=tx-n/2;i++) ans-=x[i];
		}
		else if(ty>=tx&&ty>=tz){
			sort(y+1,y+ty+1);
			for(int i=1;i<=ty-n/2;i++) ans-=y[i];
		}
		else{
			sort(z+1,z+tz+1);
			for(int i=1;i<=tz-n/2;i++) ans-=z[i];
		}
		cout<<ans<<endl;
	}
}
