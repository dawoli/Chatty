#include<bits/stdc++.h>
using namespace std;
struct car{
	double d,v,a,fine;
	int start,end;
}nt;
car p[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,L,V,ans=0;
		cin>>n>>m>>L>>V;
		//nt.d=0;nt.end=0;nt.fine=0;nt.a=0;nt.start=0;nt.v=0;
		//memset(nt,p,sizeof(p));
		int stop[100005];
		for(int i=0;i<n;i++){
			cin>>p[i].d>>p[i].v>>p[i].a;
			p[i].fine=L+1;
			int tmp;
			if(p[i].a<0&&p[i].v<=V){
				p[i].fine=L+1;
			}else{
				if(p[i].a!=0){
					tmp=(V*V-p[i].v*p[i].v)/2;
					p[i].fine=p[i].d+tmp/p[i].a;
				}else if(p[i].a==0){
					if(p[i].v>V){
						p[i].fine=p[i].d;
					}else{
						p[i].fine=L+1;
					}
				}
			}		
			//cout<<p[i].fine<<endl;
		}
		for(int i=0;i<m;i++){
			cin>>stop[i];
		}
		for(int i=0;i<n;i++){
			if(p[i].fine>L)continue;
			for(int j=1;j<m;j++){
				if(p[i].fine<stop[j]&&p[i].fine>stop[j-1]){
					p[i].end=stop[j-1];
				}
				if(p[i].d<stop[j]&&p[i].d>stop[j-1]){
					p[i].start=stop[j-1];
				}
			}
		}
		for(int i=0;i<n;i++){
			if(p[i].fine>L){
				continue;
			}
			if(p[i].a<V){
				if(p[i].fine>stop[0]){
					ans++;
				}
			}else{
				if(p[i].fine<stop[m]){
					ans++;
				}
			}
		}
		cout<<ans<<" "<<ans<<endl;
	}
} 

