#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
long long T;
long long n,m,l,v;//车辆数量 测速仪数量 主干道长度 道路限速
long long det[N];
struct car{
	long long d,v,a;
} cars[N];
struct stru{
	long long l,r,num;
} f[101010]; 
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	
	while(T--){
	
		cin>>n>>m>>l>>v;
		for(long long i=1;i<=n;i++){
			cin>>cars[i].d>>cars[i].v>>cars[i].a;
		}
		for(long long i=1;i<=m;i++){
			cin>>det[i];
		}
		sort(det+1,det+1+m);
		memset(f,0,sizeof(f));
		long long cnt=0;
		for(long long i=1;i<=n;i++){
			
			double s=0,e=0;
			if(cars[i].a==0){
				if(cars[i].v>v){
					s=cars[i].d;
					f[i].l=lower_bound(det+1,det+1+m,s)-det;
					f[i].r=m;
					f[i].num=f[i].r-f[i].l+1; 
				}
				else f[i].l=0,f[i].r=0,f[i].num=0;
			}
			else if(cars[i].a>0){
				if(cars[i].v>v){
					s=cars[i].d;
					f[i].l=lower_bound(det+1,det+1+m,s)-det;
					f[i].r=m;
					f[i].num=f[i].r-f[i].l+1; 
				}
				else{
					s=(pow(v,2)-pow(cars[i].v,2))/(2.0*cars[i].a)+cars[i].d;
					f[i].l=upper_bound(det+1,det+1+m,s)-det;
					f[i].r=m;
					f[i].num=f[i].r-f[i].l+1; 
				}	
			}
			else if(cars[i].a<0){
				if(cars[i].v<=v) f[i].l=0,f[i].r=0,f[i].num=0;
				else{
					s=cars[i].d;
					e=(pow(v,2)-pow(cars[i].v,2))/(2.0*cars[i].a)+cars[i].d;
					f[i].l=lower_bound(det+1,det+1+m,s)-det;
					f[i].r=lower_bound(det+1,det+1+m,e)-det-1;
					f[i].num=f[i].r-f[i].l+1;
				}
			}
			if(f[i].num>0){
				cnt++;
			}
		}
		 
		cout<<cnt<<" ";
		long long ccnt=0;
		long long aa=0;
		for(long long i=1;i<=m;i++){
			aa=1;
			for(long long j=1;j<=n;j++){
				if(f[j].l==i&&f[j].num==1){
					aa=0;
					break;
				}
			}
			if(aa==1){
				for(long long j=1;j<=n;j++){
					if(i>=f[j].l&&i<=f[j].r) f[j].num--,f[j].l++;
				}
				ccnt++;
			}
		}
		cout<<ccnt<<endl;
	}
	
	return 0;
} 
