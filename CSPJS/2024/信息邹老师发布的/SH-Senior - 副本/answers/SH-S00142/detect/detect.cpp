#include <bits/stdc++.h>
using namespace std;
int T,n,m,l,vmax,d[100010],v[100010],a[100010];
int p[100010];
struct Chaosu{
	double start=0,end=0;//开始超速的位置和结束超速状态的位置
	double vis=false;//是否超速，true代表会超速，false代表不超速 
}car[100010];
vector<int> check[100010];
void init(){
	for(int i=0;i<n;i++)
		car[i].start=0,car[i].end=0,car[i].vis=false;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		long long minus=0,add=0,zero=0;
		long long ans=0;
		scanf("%d%d%d%d",&n,&m,&l,&vmax);
		init();
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
			if(a[i]>0) add++;
			else if(a[i]<0) minus++;
			else zero++;
		}
		for(int i=0;i<m;i++)
			scanf("%d",&p[i]);
		for(int i=0;i<n;i++){
			if (a[i]==0){
				if(v[i]>vmax){
					car[i].start=d[i],car[i].end=l,car[i].vis=true;
//					cerr<<"Case"<<i<<"在"<<d[i]<<"开始超速"<<endl;
					continue;
				}
				else
//					cerr<<"Case"<<i<<"没有超速"<<endl;
					continue;
			}
//			if(a[i]==0) cerr<<"aaaaa";
			double x=(vmax*vmax*1.0000000-v[i]*v[i]*1.0000000000)/2/a[i]/1.00000000000;
//			cerr<<"Case"<<i<<": 超速位置"<<x<<" 在 ";
			if(a[i]<0){
				car[i].start=d[i],car[i].end=min((double)l,d[i]+x),car[i].vis=true;
//				cerr<<d[i]<<"到"<<d[i]+x<<"范围内"<<endl;
			}
			else if(a[i]>0){
				if(d[i]+x>l) continue;
				car[i].end=l,car[i].start=d[i]+x,car[i].vis=true;
//				cerr<<d[i]+x<<"到"<<l<<"范围内"<<endl;
			}
//			cerr<<endl;
		}
		for(int i=0;i<n;i++)
			if(car[i].vis==true)
				ans++;
		for(int i=0;i<n;i++){
			if(car[i].vis==true){
				bool f=false;
				double sttime=car[i].start,endtime=car[i].end;
				for(int j=0;j<m;j++){
					if(p[j]>=sttime&&p[j]<=endtime){
//						cerr<<i<<"判断正确"<<sttime<<" "<<endtime<<" "<<j<<" "<<p[j]<<endl;
						f=true;
						check[j].push_back(i);
					}
				}
				if(f==false){
					ans--;
					car[i].vis=false;
//					cerr<<i<<"判断错误"<<car[i].start<<" "<<car[i].end<<endl;
				}
			}
		}
		printf("%lld ",ans);
//		cerr<<"第一个输出"<<ans;
		if(zero==n){
			if(ans==0){
				printf("%d\n",m);
//				cerr<<"第二个输出"<<m<<endl;
			}
			else{
				printf("%d\n",m-1);
//				cerr<<"第二个输出"<<m-1<<endl;
			}
		}
		else if(add==n){
			if(ans==0){
				printf("%d\n",m);
//				cerr<<"第二个输出"<<m<<endl;
			}
			else{
				printf("%d\n",m-1);
//				cerr<<"第二个输出"<<m-1<<endl;
			}
		}
	}
	return 0;
}
