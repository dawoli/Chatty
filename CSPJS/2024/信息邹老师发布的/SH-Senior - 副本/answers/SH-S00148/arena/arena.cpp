#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 2000010
#define fo(i,a,b) for(ll i=(a);i<=(b);i++)
#define rep(i,a,b) for(ll i=(a);i>=(b);i--)
ll n,m,t,q;

ll aa[maxn],c[maxn],a[maxn];
char D[20][maxn];
bool d[20][maxn];
vector<int> ans;
pair<int,int> A[maxn];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>q;
	fo(i,1,n)cin>>a[i];
	fo(i,1,q)cin>>c[i];
	int tmp=n;
	tmp--;
	m=0;
	while(tmp){
		m++;
		tmp/=2;
	}
	fo(i,1,m){
		fo(j,1,1<<(m-i)){
			cin>>D[i][j];
			d[i][j]=(D[i][j]=='1');
//			cout<<d[i][j];
		}//cout<<endl;
	}
	cin>>t;
	while(t--){
		int X[4];
		fo(i,0,3)cin>>X[i];
		fo(i,1,n)a[i]=aa[i]^X[i%4],A[i]=make_pair(a[i],i);
		fo(i,1,m){
			fo(j,1,1<<(m-i)){
				if(A[(j*2)-1].first>=i){
					A[j]=A[(j*2)-1];
				}
			}
		}
		ll sum=0;
		fo(i,1,q){
			int tmp=c[i];
			tmp--;
			int cc=0;
			while(tmp){
				cc++;
				tmp/=2;
			}
			sum+=A[m-cc+1].second;
		}
		ans.push_back(sum);
	}
	int rans=0;
	fo(i,0,(int)ans.size()-1){
		rans^=(i+1)*ans[i];
	}
	cout<<rans;
	return 0;
}
//想写游记，但是来不及了，伤心。 
