#include<bits/stdc++.h>
using namespace std;
int t,b[100005],flag,ans1,ans2;
struct node{
	int d,v,a,e;
};
node c[100005];
void solvea(int n,int m,int l,int lim){
	for(int i=1;i<=n;i++){
		if(c[i].v>lim){
			if(c[i].d<=b[m]) ans1++;
		}
	}
	ans2=m-1;
	if(ans1==0) ans2++;
}
void solveb(int n,int m,int l,int lim){
	int del;
	for(int i=1;i<=n;i++){
		if(c[i].v>lim) continue;
		else{
			del=(lim*lim-c[i].v*c[i].v)/(2*c[i].a);
			if(del*2*c[i].a==lim*lim-c[i].v*c[i].v) del++;
			c[i].d+=del;
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i].d<=b[m]){
			ans1++;
		}
	}
	ans2=m-1;
	if(ans1==0) ans2++;
}
//void solvec(int n,int m,int l,int lim){
//	unordered_set <int> s[100005];
//	vector <int> v;
//	bool f[100005];
//	memset(f,0,sizeof(f));
//	for(int i=1;i<=n;i++){
//		if(c[i].v>lim){
//			if(c[i].a>=0) c[i].e=l;
//			else{
//				del=(lim*lim-c[i].v*c[i].v)/(2*c[i].a);
//				if(del*2*c[i].a==lim*lim-c[i].v*c[i].v) del--;
//				c[i].d+=del;
//				c[i].d=,in(c[i].d,l);
//			}
//		}
//		else if(c[i].v==lim){
//			if(c[i].a>0) c[i].e=l;
//			else f[i]=1;
//		}
//		else {
//			if(a>0){
//				del=(lim*lim-c[i].v*c[i].v)/(2*c[i].a);
//				if(del*2*c[i].a==lim*lim-c[i].v*c[i].v) del++;
//				c[i].d+=del;
//				if(c[i].d>l) f[i]=1;
//			}
//			else{
//				f[i]=1;
//			}
//		}
//	}
//	for(int i=1;i<=n;i++){
//		if(f[i]){
//			continue;
//		}
//		ans1++;
//		int cnt=upper_bound(b+1,b+m+1,c[i].d)-b;
//		if(b[cnt]>c[i].e){
//			f[i]=1;
//			ans1--;
//		}
//		while(b[cnt]<=c[i].e){
//			s[cnt].inset(i);
//			cnt++;
//		}
//	}
//	
//}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		int n,m,l,lim;
		flag=0,ans1=0,ans2=0;
		cin>>n>>m>>l>>lim;
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
			if(flag==1&&c[i].a!=0) flag=3;
			if(flag==2&&c[i].a<=0) flag=3;
			if(flag==0){
				if(c[i].a==0) flag=1;
				else if(c[i].a>0) flag=2;
				else flag=3;
			}
		}
		for(int i=1;i<=m;i++){
			cin>>b[i];
		}
		if(flag==1){
			solvea(n,m,l,lim);
		}
		else if(flag==2){
			solveb(n,m,l,lim);
		}
//		else{
//			solvec(n,m,l,lim);
//		}
		cout<<ans1<<" "<<ans2<<endl;
	}
}
