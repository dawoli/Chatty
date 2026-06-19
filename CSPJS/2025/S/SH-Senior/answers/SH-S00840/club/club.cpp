#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N=1e5+10;
int n,a[N][3],aa[N][3];
pair<int,int>b[N];
void fun(int x){
	if(a[x][0]<a[x][1])swap(a[x][0],a[x][1]),swap(aa[x][0],aa[x][1]);
	if(a[x][1]<a[x][2])swap(a[x][1],a[x][2]),swap(aa[x][1],aa[x][2]);
	if(a[x][0]<a[x][1])swap(a[x][0],a[x][1]),swap(aa[x][0],aa[x][1]);
}
int cnt[3];
bool bl[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			aa[i][0]=0,aa[i][1]=1,aa[i][2]=2;
			fun(i);
			b[i]=make_pair(a[i][0]-a[i][1],i);
		}
		memset(bl,0,sizeof bl);
		sort(b+1,b+n+1);
		reverse(b+1,b+n+1);
		cnt[0]=cnt[1]=cnt[2]=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(cnt[aa[b[i].se][0]]+1>(n/2)){
				;
			}else{
				cnt[aa[b[i].se][0]]++;
				sum+=a[b[i].se][0];
				bl[b[i].se]=1;
			}
		}
		int tot=0;
		for(int i=1;i<=n;i++){
			if(!bl[i]){
				b[++tot]=make_pair(a[i][1]-a[i][2],i);
			}
		}
		sort(b+1,b+tot+1);
		reverse(b+1,b+tot+1);
		for(int i=1;i<=tot;i++){
			if(bl[b[i].se])continue;
			if(cnt[aa[b[i].se][1]]+1>(n/2)){
				cnt[aa[b[i].se][2]]++;
				sum+=a[b[i].se][2];
			}else{
				cnt[aa[b[i].se][1]]++;
				sum+=a[b[i].se][1];
			}
		}
	//	cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<endl;
		cout<<sum<<endl;
	}
	return 0;
} 
