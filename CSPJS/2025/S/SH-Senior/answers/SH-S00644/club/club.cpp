#include<fstream>
#include<algorithm>
std::fstream fin("club.in",std::ios::in),fout("club.out",std::ios::out);
int t,n,cnt[3];
long long ans;
struct Trair{
	int a[3],x,y,f;
}a[100001];
int main(){
	fin >> t;
	while(t--){
		fin >> n,cnt[0]=cnt[1]=cnt[2]=ans=0;
		for(int i{0};i<n;++i){
			fin >> a[i].a[0] >> a[i].a[1] >> a[i].a[2],a[i].f=(a[i].a[0]==a[i].a[1])+(a[i].a[2]==a[i].a[1])+(a[i].a[0]==a[i].a[2]);
			if(a[i].a[0]>a[i].a[1])a[i].x=0,a[i].y=1;
			else a[i].y=0,a[i].x=1;
			if(a[i].a[2]>a[i].a[a[i].x])a[i].y=a[i].x,a[i].x=2;
			else if(a[i].a[2]>a[i].a[a[i].y])a[i].y=2;
		}
		std::sort(a,a+n,[&](Trair& x,Trair& y)->bool{
			return x.a[x.x]-x.a[x.y]>y.a[y.x]-y.a[y.y];
		});
		for(int i{0},s{n>>1};i<n;++i)
			if(cnt[a[i].x]<s)++cnt[a[i].x],ans+=a[i].a[a[i].x];
			else{
				if(!a[i].f)++cnt[a[i].y],ans+=a[i].a[a[i].y];
				else if(a[i].f==1){
					if(a[i].x==a[i].y)++cnt[a[i].y],ans+=a[i].a[a[i].y];
					else ans+=a[i].a[a[i].y];
				}
				else ans+=a[i].a[0];
			}
		fout << ans << '\n';
	}
}
