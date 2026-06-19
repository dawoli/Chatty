#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int t,n,m,L,V;
int ans=0,cnt,sum;
int d[N],v[N],a[N],p[N];
struct node{
	int l,r;
	bool operator<(const node&b) const{
		return r<b.r;
	}
}block[N];
inline void search(int d){
	int tag=lower_bound(p+1,p+m+1,d)-p;
	if(tag>m) return;
	else{
		ans++;
		block[++cnt]=(node){tag,m}; //记录数量，这个是超速 
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout); 
	cin>>t;
	while(t--){
		ans=0; cnt=0;
		cin>>n>>m>>L>>V;
		memset(block,0,sizeof(block));
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]>0){
				if(v[i]>V){
					search(d[i]);
				}
				else{
					int nd=(V*V-v[i]*v[i])/(2*a[i])+d[i]+1; //强转浮点如果出的尽，那那一刻也不可能超速，除不尽那一刻也不会有摄像头 
					search(nd);
				}
			}
			else if(a[i]==0){
				if(v[i]<=V) continue;
				else{
					search(d[i]);
				}
			}
			else{
				if(v[i]<=V) continue;
				else{
					int nd=0;
					if((V*V-v[i]*v[i])%(2*a[i])==0) nd=(V*V-v[i]*v[i])/(2*a[i]);
					else nd=(V*V-v[i]*v[i])/(2*a[i])+1;
					int tag1=lower_bound(p+1,p+m+1,d[i])-p;//超速段落
					int tag2=lower_bound(p+1,p+m+1,d[i]+nd)-p;//不超速段落 
					if(tag1==tag2) continue;
					else{
						ans++;
						block[++cnt]=(node){tag1,tag2-1};
					}
				}
			}
		}
		cout<<ans;
		sort(block+1,block+1+cnt);
		sum=0;
		int tagg=0;
		for(int j=1;j<=cnt;j++){
			if(block[j].l<=tagg) continue;
			else{
				sum++;
				tagg=block[j].r;
			}
		}
		cout<<" "<<m-sum<<endl;
	}
	return 0;
}
