#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+9;
int n,m,L,V,d[N],v[N],a[N],lB[N],rB[N],p[N];
bool bigger[N];
struct car{
	int l,r;
	bool operator<(const car & ano)const{
		return r<ano.r;
	}	
} obcar[N];
int nob;	
//int CD(int a,int b){return floor((long double)1.0*(a+b-1)/b);} 
int CD(int a,int b){return ceil((long double)1.0*a/b);} 
signed main(){
//	cout<<-5/2<<endl;
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		scanf("%ld%ld%ld%ld",&n,&m,&L,&V);
//		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			scanf("%ld%ld",&d[i],&v[i]);
			cin>>a[i];
//			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=n;i++){
			bigger[i]=0;
			if(a[i]==0){
				if(v[i]>V){
					bigger[i]=1;
					lB[i]=d[i];
					rB[i]=L;
				}
			}
			else if(a[i]>0){
				//由于一直加速所以一点会超速 
				//如果开始超速点<=L 
				
				if(v[i]>V){
					bigger[i]=1;
					lB[i]=d[i];
					rB[i]=L;
				}else if((V*V-v[i]*v[i])/(2*a[i])+1+d[i]<=L){
					bigger[i]=1;//标记超速 
					lB[i]=(V*V-v[i]*v[i])/(2*a[i])+1+d[i];//从这个点开始超速 
					rB[i]=L;//一直超速的末端 
				}
			}
			else{
				if(v[i]>V){//如果开始时超速(因为一直在减速，所以等价于开始时超速) 
//				if(CD(V*V-v[i]*v[i],2*a[i])<=min(-v[i]/a[i],L)){
					bigger[i]=1;//标记超速 
					lB[i]=d[i];//从开始开始超速 
					rB[i]=min(L,d[i]+CD(V*V-v[i]*v[i],2*a[i])-1);
					//要么在末尾还在超速 
					//要么某个点结束超速 
//					lB[i]=CD(V*V-v[i]*v[i],2*a[i]);
//					rB[i]=L;
				}
			}
//			cout<<bigger[i]<<" "<<lB[i]<<" "<<rB[i]<<endl;
		}
		for(int i=1;i<=m;i++){
			scanf("%ld",&p[i]);
//			cin>>p[i];
		}
		int res=0;
		for(int i=1;i<=n;i++){
			if(bigger[i]==0)continue;
			lB[i]=lower_bound(p+1,p+1+m,lB[i])-p;
			rB[i]=upper_bound(p+1,p+1+m,rB[i])-p-1;
			if(lB[i]>rB[i]){
				bigger[i]=0;
				continue;
			}
			res++;
		}
		nob=0;
		for(int i=1;i<=n;i++){
			if(bigger[i]){
				nob++;
				obcar[nob].l=lB[i];
				obcar[nob].r=rB[i];
			}
		}
		int ans=0,last=-1;
		sort(obcar+1,obcar+1+nob);
		for(int i=1;i<=nob;i++){
//			cout<<obcar[i].l<<" "<<obcar[i].r<<endl;
			if(obcar[i].l<=last)continue;
			ans++;
			last=obcar[i].r;
		}		
		printf("%ld %ld\n",res,m-ans);
//		cout<<res<<endl;
	}
	return 0;
}
