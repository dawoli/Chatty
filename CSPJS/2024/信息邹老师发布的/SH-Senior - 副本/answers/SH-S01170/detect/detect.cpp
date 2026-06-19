#include<bits/stdc++.h>
using namespace std;
int t,ans,cnt;
struct S{
	int d,v,a;
}d[100005];
int p[100005];
bool q[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		ans=0;
		cnt=0;
		int n,m,l,V;
		cin>>n>>m>>l>>V;
		for(int j=0;j<n;j++){
			cin>>d[j].d>>d[j].v>>d[j].a;		
		}
		for(int j=0;j<m;j++){
			cin>>p[j];
		}
		for(int j=0;j<n;j++){
			if(d[j].a>=0&&d[j].v>V){
				int id;
				for(int k=0;k<m;k++){
					if(d[j].d>p[k]){
						id=k;
						ans++;
						break;
					}
				}
				q[id]=1;
				
			}
			else if(d[j].a<0&&d[j].v>V){
				int minn=2147483647,id;
				for(int k=0;k<m;k++){
					if(d[j].d<p[k]&&p[k]-d[j].d<minn){
						minn=p[k]-d[j].d;
						id=k;
					}
				}
				double y=(V*V-d[j].v*d[j].v)/(2*d[j].a);
				if(double(y>minn)) q[id]=1,ans++;
			}else{
				int minn=2147483647,id;
				double y=(V*V-d[j].v*d[j].v)/-4;
				for(int k=0;k<m;k++){
					if(d[j].d+y<p[k]){
						id=k;
						ans++;
						break;
					}
				}
			    if(id!=0) q[id]=1;
			}
		}
		cout<<ans<<" ";
		for(int i=0;i<m;i++){
			if(q[i]==0) cnt++;
		}
		cout<<cnt;
	}
	return 0;
}
