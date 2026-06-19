#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=1e5+10,L=1e6+10,inf=0x3f3f3f3f;
int n,m,len,v,cr[N][5],p[N],tot,b[L],cnt,dp[L][2];
pii fw[N];
bool bl[N];
void fun(int x){
	int d=cr[x][1],vv=cr[x][2],a=cr[x][3];
	if(vv<=v&&a<=0)return ;
	double l,r,t;
	t=(v-vv)*1.0/a;
	if(vv>v){
		l=d;
		if(a>=0)r=len+1;
		else r=min((double)len,d+t*vv+t*t*a*0.5);
		if(r==(int)r)r--;
		else r=(int)r;
	}else{
		l=d+(v*v-vv*vv)*1.0/2/a;
		if(l>len)return ;
		if(l==(int)l)l++;
		else l=((int)l)+1;
		r=len;
	}
	bool flag;
	int ll=l,rr=r;
	if(ll==0)flag=(bool)b[rr];
	else flag=(bool)(b[rr]-b[ll-1]);
	cnt+=flag;
	if(flag)fw[++tot]=make_pair(r,l);
	//cout<<l<<" "<<fw[tot].first<<" "<<fw[tot].second<<" "<<x<<endl;
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>m>>len>>v;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)cin>>cr[i][j];
		for(int i=0;i<=len+1;i++)b[i]=0,dp[i][0]=dp[i][1]=inf;	
		for(int i=0;i<=n;i++)bl[i]=0;
		for(int i=1;i<=m;i++)cin>>p[i],b[p[i]]++;
		for(int i=1;i<=len;i++)b[i]+=b[i-1];
		cnt=0;
		for(int i=1;i<=n;i++)fun(i);
		cout<<cnt<<" "; 
		sort (fw+1,fw+tot+1);
		//for(int i=1;i<=tot;i++)cout<<fw[i].first<<" "<<fw[i].second<<endl;
		
		//for(int i=1;i<=m;i++)cout<<p[i]<<" ";
		//cout<<endl;
		int j=1;
		if(fw[1].first==0){
			j++;
			dp[0][1]=1;
		}else{
			dp[0][0]=0;
			dp[0][1]=1;
		}
		int maxr=0;
		for(int i=1;i<=len;i++){
			int tt=0;
			int maxx=0;
			int lstr=maxr;
			while(fw[j].first==i&&j<=tot){
//				if(bl[j]==0){
//					j++;
//					continue;
//				}
				//st.insert(fw[j].second);
				maxx=max(maxx,fw[j].second);
				//cout<<fw[j].first<<endl;
				j++;
				tt++;
				maxr=max(maxr,fw[j].first);
			}
			//if(tt)cout<<lstr<<endl;
			//cout<<tt<<" ";
			if(tt==0){
				dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
			}else{
//				if(maxx=-1)dp[i][0]=inf;
//				else dp[i][0]=dp[maxx][1];
				if(lstr<maxx){
					for(int j=maxx;j<i;j++)dp[i][0]=min(dp[j][1],dp[i][0]);
				}
				else {
					for(int j=maxx;j<=lstr;j++)dp[i][0]=min(dp[j][1],dp[i][0]);
					dp[i][0]=min(dp[i][0],dp[lstr][0]+1);
				}
				//cout<<maxr<<endl;
			//	cout<<i<<" "<<lstr<<" "<<maxx<<" "<<dp[i][0]<<" "<<dp[i][1]<<" "<<endl;
			}
			if(b[i]-b[i-(bool)(i>0)]==1||(i==0&&b[i]==1)){
				dp[i][1]=min(dp[i-1][0],dp[i-1][1])+1;
				//cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
			}
			//cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
			//
			//if(tt)lst=i;
		} 
		cout<<m-min(dp[len][0],dp[len][1])<<endl;
	}
	return 0;
} 
