#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v,p[100005],ans1,ans2,cnt;
float maxpre;
struct car{
	int d,a,v,ch/*是否超速*/,tf;
	float lim,pre,las; 
}c[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>l>>v;
		ans1=0;
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
			if(c[i].v>v&&c[i].a>=0){
				c[i].ch=1;
				c[i].pre=c[i].d;
				c[i].las=l;
			} 
			else if(c[i].v>v&&c[i].a<0){
				if((c[i].d+(v*v-c[i].v*c[i].v)/(2*c[i].a))>l){
					c[i].ch=1;
					c[i].pre=c[i].d;
					c[i].las=l;
				}
				else{
					c[i].lim=(c[i].d+(v*v-c[i].v*c[i].v)/(2*c[i].a));
					c[i].pre=c[i].d;
					c[i].las=c[i].lim;
				}
			} 
			else if(c[i].v<v&&c[i].a>0){
				c[i].lim=c[i].d+(v*v-c[i].v*c[i].v)/(2*c[i].a);
				c[i].pre=c[i].lim ;
				c[i].las=l;
			} 
			else if(c[i].v<v&&c[i].a<=0){
				c[i].ch=2;
			}
			else if(c[i].v==v&&c[i].a>0){
				c[i].pre=c[i].d;
				c[i].las=c[i].d;
			}
			else if(c[i].v==v&&c[i].a<=0){
				c[i].ch=2;
			}
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			if(c[i].ch==2) {
				ans1+=0;
			}
			else if(c[i].ch==1){
				ans1++;
				c[i].tf=1;
			}else{
				for(int j=1;j<=m;j++){
					if(c[i].pre<=p[j]&&p[j]<(c[i].las)){
						ans1++;
						c[i].tf=1;
						break;
					}	
				}
			}
		}
		maxpre=0;
		for(int i=1;i<=n;i++){
			if(c[i].tf==1){
				maxpre=max(maxpre,c[i].pre);
			}
		}
		ans2=1;
		while(p[m]<=maxpre){
			ans2++;
		}
		cnt=0;
		cout<<ans1<<" ";
		for(int i=1;i<=n;i++){
			if(c[i].tf==1){
				cnt=1;
			}
		}
		if(cnt==1){
			cout<<m-1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	return 0;
}
//分类讨论
//(1)v0>v限 a<0  可能超速 
//(2)v0>v限 a>=0 肯定超速 
//(3)v0<v限 a<=0 永不超速 
//(4)v0<v限 a>0  可能超速
//算出超速距离 
//公式(c[i].d+(v*v-c[i].v*c[i].v)/(2*c[i].a))
