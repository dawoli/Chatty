#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e3+5;
int T,n,m,len,limit,pos[N],car[N],a[N],v[N];
int legal(int i,int j){
	if(car[i]<=pos[j]){
		int move=pos[j]-car[i];
		if(a[i]<0){
			if(-2*v[i]*v[i]+a[i]*v[i]*v[i]+2*a[i]*car[i]>2*a[i]*pos[j]){
				return 0;
			} 
		} 
		int s=v[i]*v[i]+2*a[i]*move;
		if(s>limit*limit){
		    return 1;    
		}
	}
	return 0;
}
pair<int,bitset<N>>dat[N];
int cmp(pair<int,bitset<N>>&x,pair<int,bitset<N>>&y){
	return x.second.count()>y.second.count();
}
void Sort(int start){
	sort(dat+start,dat+m+1,cmp);
}
signed main(){
	freopen("detect.in","r",stdin),freopen("detect.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>len>>limit;
		for(int i=1;i<=n;i++){
			cin>>car[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>pos[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int ok=0;
			for(int j=1;j<=m;j++){
				ok|=legal(i,j);
			}
			ans+=ok;
		}
		cout<<ans<<" ",ans=0;
		for(int i=1;i<=m;i++){
			dat[i].first=i;
			for(int j=1;j<=n;j++){
				if(legal(j,i)){
					dat[i].second[j]=1;
				}
				else{
					dat[i].second[j]=0;
				}
			}
		}
		Sort(1);
        for(int i=1;i<=m;i++){
        	if(dat[i].second.count()){
        		ans++;
        		auto tmp=dat[i].second;
        		for(int j=1;j<=n;j++){
        			tmp[j]=!tmp[j];
				}
        		for(int j=i+1;j<=m;j++){
        			dat[j].second&=tmp;
				}
			}
			else{
				break;
			}
			Sort(i+1);
		}
		cout<<m-ans<<'\n';
	}
}
