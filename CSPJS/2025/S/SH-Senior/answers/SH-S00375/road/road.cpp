#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,a[15][10005],s,y,cnt,c[15],fp[100005],ans,fa,fb,minn = 4e18;
bool f = 1;
struct edge{
	long long f,t;
	long long len;
	long long ne;
}e[200005];
bool cmp(edge a,edge b){
	return a.len < b.len;
}
int find(long long x){
	if(fp[x] == x){
		return x;
	}
	else{
		fp[x] = find(fp[x]);
		return fp[x];
	}
}
bool check(){
	long long s = find(1);
	for(int i = 2;i <= n;i++){
		if(s != find(i)){
			return false;
		}
	}
	return true;
}
int gb(int n){
	int ans = 0;
	while(n){
		n -= (n&(-n));
		ans++;
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++){
		cin>>u>>v>>w;
		cnt++;
		e[cnt].f = u;
		e[cnt].t = v;
		e[cnt].len = w;
		e[cnt].ne = 0;
	}
	for(int i = 1;i <= k;i++){
		cin>>c[i];
		for(int j = 1;j <= n;j++){
			cin>>a[i][j];
			cnt++;
			e[cnt].f = n+i;
			e[cnt].t = j;
			e[cnt].len = a[i][j];
			e[cnt].ne = i;
		}
	}
	sort(e+1,e+cnt+1,cmp);
	if(k == 0){
		ans = 0;
		s = 0;
		for(int i = 1;i <= n;i++){
			fp[i] = i;
		}
		for(int i = 1;i <= cnt;i++){
			if(s >= n-1){
				break;
			}
			fa = find(e[i].f);
			fb = find(e[i].t);
			if(fa != fb){
				fp[fb] = fa;
				ans += e[i].len;
				s++;
			}
		}
		minn = ans;
	}
	else{
		for(int i = 0;i < (1<<k);i++){
			y = gb(i);
			ans = 0;
			s = 0;
			for(int j = 1;j <= k;j++){
				if(((i>>(j-1))&1) == 1){
					ans += c[j];
				}
			}
			for(int j = 1;j <= n+k;j++){
				fp[j] = j;
			}
			for(int j = 1;j <= cnt;j++){
				if(s >= n+y-1){
					break;
				}
				if(((i>>(e[j].ne-1))&1) == 1 || e[j].ne == 0){
					fa = find(e[j].f);
					fb = find(e[j].t);
					if(fa != fb){
						fp[fb] = fa;
						ans += e[j].len;
						s++;
					}
				}
			}
			minn = min(minn,ans);
		}
	}
	cout<<minn<<endl;
	return 0;
}
