#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
int n,m,L,v;
struct car{
	int d,vcar,a;
}in[N];
int p[N];
bool check1(int l,int r){
	int lduan=1,rduan=m;
	while(lduan<=rduan){
		int mid=(lduan+rduan)>>1;
		if(p[mid]>=l&&p[mid]<=r)return 1;
		else if(p[mid]>r)rduan=mid;
		else if(p[mid]<l)lduan=mid+1;
	}
	return 0;
}
bool check2(int l,int r){
	int lduan=1,rduan=m;
	while(lduan<=rduan){
		int mid=(lduan+rduan)>>1;
		if(p[mid]>l&&p[mid]<=r)return 1;
		else if(p[mid]>r)rduan=mid;
		else if(p[mid]<=l)lduan=mid+1;
	}
	return 0;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>L>>v;
		for(int i=1;i<=n;i++){
			cin>>in[i].d>>in[i].vcar>>in[i].a;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(in[i].a==0){
				if(in[i].vcar<=v)continue;
				else{
					if(check1(in[i].d,L))ans++;
				} 
			}else if(in[i].a>0){
				if(in[i].vcar>v){
					if(check1(in[i].d,L))ans++;
				}else{
					if(2*in[i].a*in[i].d+v*v>=L*2*in[i].a+in[i].vcar*in[i].vcar)continue;
					else{
						if(check2(in[i].d+(v*v-in[i].vcar*in[i].vcar)/(2*in[i].a),L))ans++;
					} 
				}
			}
		}
		cout<<ans<<" ";
		if(!ans)cout<<m<<endl;
		else cout<<m-1<<endl;
	}
	return 0;
}
