#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=100015,L=1000015;
int n,m,len;
long double v;
PII seg[N];
int a[N],b[L];
bool st[L];
long double Speed(long double vz,int ac,int s){
	if(vz*vz+2*ac*s<0)return 0;
	return sqrt(vz*vz+2*ac*s);
}
struct node{
	long double v;
	int d,a;
}car[N];
int count_zero(int x){
	int ret=0;
	while(x){
		if(x%2==0)ret++;
		x>>=1;
	}
	return ret;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(st,0,sizeof st);
		cin>>n>>m>>len>>v;
		for(int i=1;i<=n;i++){
			scanf("%d",&car[i].d);
			cin>>car[i].v;
			scanf("%d",&car[i].a);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
			st[a[i]]=1;
		}
		int id=1,ans_1=0,cnt=0;
		for(int i=0;i<=len;i++){
			b[i]=id;
			if(st[i])id++;
		}
		for(int i=1;i<=n;i++){
			int l=b[car[i].d],r=m;
			if(car[i].a==0){
				if(car[i].v>v){
					seg[++cnt]={l,m};
					ans_1++;
				}
			}
			else if(car[i].a>0){
				if(Speed(car[i].v,car[i].a,a[m]-car[i].d)<=v){
					continue;
				}
				while(l<r){
					int mid=l+r>>1;
					if(Speed(car[i].v,car[i].a,a[mid]-car[i].d)>v){
						r=mid;
					}
					else l=mid+1;
				}
				seg[++cnt]={l,m};
				ans_1++;
			}
			else if(car[i].a<0){
				if(Speed(car[i].v,car[i].a,a[l]-car[i].d)<=v){
					continue;
				}
				while(l<r){
					int mid=l+r>>1;
					if(Speed(car[i].v,car[i].a,a[mid]-car[i].d)<=v){
						r=mid;
					}
					else l=mid+1;
				}
				seg[++cnt]={b[car[i].d],l};
				ans_1++;
			}
		}
		int ans_2=m-1;
		if(m<=20){
			ans_2=0;
			for(int i=0;i<1<<m;i++){
				bool Flag=1;
				for(int j=1;j<=cnt;j++){
					bool flag=0;
					for(int k=0;k<m;k++){
						if((i>>k)&1){
							if(a[k+1]>=seg[j].first&&a[k+1]<=seg[j].second){
								flag=1;
								break;
							}
						}
					}
					if(flag==0){
						Flag=0;
						break;
					}
				}
				if(Flag==1)ans_2=max(ans_2,count_zero(i));
			}
			ans_2=m-ans_2;
		}
		cout<<ans_1<<' '<<ans_2<<endl;
	}
	return 0;
}
