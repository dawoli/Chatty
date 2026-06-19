#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
int T,n,l[5],s[5];
struct stu{
	int d[5],f1,f2;
} a[100005];
bool cmp(stu x,stu y){
	return x.d[x.f1]+y.d[y.f2]>x.d[x.f2]+y.d[y.f1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(l,0,sizeof(l));
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++){
			cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3];
			if(a[i].d[1]>a[i].d[2]){
				if(a[i].d[1]>a[i].d[3]){
					a[i].f1=1;
					if(a[i].d[2]>a[i].d[3]) a[i].f2=2;
					else a[i].f2=3;
				}
				else a[i].f1=3,a[i].f2=1;
			}else{
				if(a[i].d[2]>a[i].d[3]){
					a[i].f1=2;
					if(a[i].d[1]>a[i].d[3]) a[i].f2=1;
					else a[i].f2=3;
				}
				else a[i].f1=3,a[i].f2=2;
			}
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(l[a[i].f1]<n/2){
				l[a[i].f1]++;
				s[a[i].f1]+=a[i].d[a[i].f1];
			}else{
				l[a[i].f2]++;
				s[a[i].f2]+=a[i].d[a[i].f2];
			}
		}
		cout<<s[1]+s[2]+s[3]<<'\n';
	}
	return 0;
}
