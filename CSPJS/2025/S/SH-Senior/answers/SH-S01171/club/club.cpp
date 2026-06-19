#include<iostream>
#include<algorithm>
using namespace std;
struct zyl{
	int a,b,c,cha,cha1;
}al[100010],bl[100010],cl[100010];
int t;
int n;
bool cmp1(zyl a,zyl b){
	if(a.cha!=b.cha)return a.cha>b.cha;
	return a.cha1>b.cha1;
}bool cmp(zyl a,zyl b){
	return a.cha>b.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		long long sum=0;
		int aa=1,bb=1,cc=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			int q,w,e;
			cin>>q>>w>>e;
			if(q==max({q,w,e})){
				al[aa].a=q;
				al[aa].b=w;
				al[aa].c=e;
				al[aa].cha=max(w-q,e-q);
				sum+=q;
				aa++;
			}else if(w==max({q,w,e})){
				bl[bb].a=q;
				bl[bb].b=w;
				bl[bb].c=e;
				bl[bb].cha=max(q-w,e-w);
				sum+=w;
				bb++;
			}else{
				cl[cc].a=q;
				cl[cc].b=w;
				cl[cc].c=e;
				cl[cc].cha=max(w-e,q-e);
				sum+=e;
				cc++;
			}
		}aa--,bb--,cc--;
		if(aa<=n/2&&bb<=n/2&&cc<=n/2)cout<<sum;
		if(aa>n/2){
			sort(al+1,al+1+aa,cmp);
			for(int i=1;i<=aa-n/2;i++){
				sum+=al[i].cha;
			}cout<<sum<<endl;
		}if(bb>n/2){
			sort(bl+1,bl+1+bb,cmp);
			for(int i=1;i<=bb-n/2;i++){
				sum+=bl[i].cha;
			}cout<<sum<<endl;
		}if(cc>n/2){
			sort(cl+1,cl+1+cc,cmp);
			for(int i=1;i<=cc-n/2;i++){
				sum+=cl[i].cha;
			}cout<<sum<<endl;
		}
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
