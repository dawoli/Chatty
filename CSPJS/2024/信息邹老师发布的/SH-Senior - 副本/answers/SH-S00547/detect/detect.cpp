#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool flag=0;
set<int> csq;
ll cnt,t,n,m,L,V;
ll d[100009],v[100009],a[100009],p[100009];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cnt=0;
		cin>>n>>m>>L>>V;
		for(int j=1;j<=n;j++)
		    scanf("%lld%lld%lld",d+j,v+j,a+j);
		for(int j=1;j<=m;j++) scanf("%lld",p+j);
		for(int j=1;j<=n;j++) if(a[j]!=0) flag=1;
		if(!flag){
		    for(int j=1;j<=n;j++)
		        if(v[j]>V&&d[j]<=p[m])
		    	    cnt++;
	    	if(cnt>0) cout<<cnt<<" "<<m-1<<endl;
	    	else cout<<cnt<<" "<<m<<endl;
	    }
	    else{
	    	for(int j=1;j<=n;j++){
	    		if(a[j]<=0){
	    			int dm;
	    			for(dm=1;dm<=m+1&&p[dm]>=d[j];dm++);
	    			if(dm<=m){
	    			    int ssv=sqrt(v[j]*v[j]+2*a[j]*(p[dm]-d[j]));
	    			    if(ssv>V) cnt++,csq.insert(dm);
	    			}
				}
				else{
					if(p[m]>=d[j]){
					    int ssv=sqrt(v[j]*v[j]+2*a[j]*(p[m]-d[j]));
					    if(ssv<0) continue;
					    if(ssv>V) cnt++,csq.insert(m);
					}
				}
			}
			cout<<cnt<<" "<<m-csq.size()<<endl;
		}
	}
	return 0;
} 
