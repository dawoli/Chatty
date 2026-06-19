#include<bits/stdc++.h>
using namespace std;
int T;
struct node{
	int be,ed;
};
bool cmp(node x,node y){
	return x.be<y.be||x.be==y.be&&x.ed<y.ed;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T-->0){
		int n,m,L,a[100010],d[100010],p[100010];
		int V,cnt=0,v[100010];
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		} 
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}			
		node tong[10010];
		for(int i=1;i<=n;i++){
			int vp=-1,ep=-1;
			long long posl=0,posr;
			if(a[i]==0){
				if(v[i]>V){
					posl=d[i];
					posr=L+1;
				}
				else posl=posr=1e9;
			}
			else if(a[i]>0){
				posl=(V*V-v[i]*v[i])/(2*a[i])+d[i];
				posr=L+1;
			}
			else {
				if(v[i]>V) posl=d[i];
				else posl=1e9;
				posr=(V*V-v[i]*v[i])/(2*a[i])+d[i];
			}
			//cout<<posl<<" "<<posr<<endl;
			bool flag=0;
			for(int j=1;j<=m;j++){
				//long long sp=v[i]*v[i]+2*a[i]*(p[j]-d[i]+1),VV=V*V;
				if(p[j]>posl&&p[j]<posr){
					//cout<<p[j]<<" ";
					if(vp==-1) vp=j;
					//if(ep<i) 
					ep=j;
				}	
			}
			if(vp!=-1&&ep!=-1){
				//cout<<i<<" "<<vp<<" "<<ep<<" "<<endl;
				cnt++;
				tong[cnt].be=vp;
				tong[cnt].ed=ep;
			}
		}
		
		sort(tong+1,tong+cnt+1,cmp);
//		for(int i=1;i<=cnt;i++){
//			cout<<tong[i].be<<" "<<tong[i].ed<<endl;
//		}
		int ans=0;
		int l=tong[1].be,r=tong[1].ed;
		for(int i=2;i<=cnt;i++){
			if(r<tong[i].be){
				ans++;
				l=tong[i].be;
				r=tong[i].ed;
			}
			else if(r>=tong[i].be){
				if(r>=tong[i].ed){
					r=tong[i].ed;
					l=tong[i].be;
				}
			}
		}
		cout<<cnt<<" "<<cnt-ans<<endl;
	}
	
	return 0;
} 
/*

*/
