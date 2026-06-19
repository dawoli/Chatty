#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long t,p[N],s[N],e[N],x[1000005],tp[1000005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		long long n,m,l,vl,ans=0;
		cin>>n>>m>>l>>vl;
		for(int i=1;i<=n;i++){
			long long d,v,a;
			cin>>d>>v>>a;
			double dis=(vl*vl-v*v)*1.0/(2*a);
			if(a<=0){
				if(v>vl){
					s[i]=d;
					if(a<0){
						if(dis>l) e[i]=l;
						else{
							if(dis/1==dis) e[i]=d+dis-1;
							else e[i]=d+floor(dis);
						}
					}
					else e[i]=l;
					if(e[i]<s[i]) s[i]=0;
				}
			}
			else{
				if(v>vl){
					s[i]=d;
					e[i]=l;
					cout<<s[i]<<" "<<e[i]<<endl;
					continue;
				}
				if(dis>=l) s[i]=0;
				else{
					if(dis/1==dis) s[i]=d+dis+1;
					else s[i]=d+ceil(dis);
				}
				e[i]=l;
				if(e[i]<s[i]) s[i]=0;
			}
			cout<<s[i]<<" "<<e[i]<<endl;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
			tp[p[i]]=1;
		}
		for(int i=1;i<=n;i++){
			if(s[i]==0) continue;
			for(int j=s[i];j<=e[i];j++){
				if(tp[j]){
					ans++;
					tp[j]++;
				}
			}
		}
		cout<<ans<<" "<<0<<endl;
	}
	return 0;
}
