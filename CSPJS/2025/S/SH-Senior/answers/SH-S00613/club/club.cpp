#include<bits/stdc++.h>
using namespace std;
int t,n,tot1,tot2,tot3,ans;
int read(){
	char ch=getchar();
	int x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
void write(int x){
	if(x/10) write(x/10);
	putchar(x%10+'0');
}
void we(int x){
	write(x);
	putchar('\n');
}
struct node{
	int x,y,z;
}ai,t1[200010],t2[200010],t3[200010];
int mxx(node a){
	return max(a.x,max(a.y,a.z));
}
bool check1(node a){
	return a.x==mxx(a);
}
bool check2(node a){
	return a.y==mxx(a);
}
bool check3(node a){
	return a.z==mxx(a);
}
bool cmp1(node a,node b){
	return a.x-max(a.y,a.z)<b.x-max(b.y,b.z);
}
bool cmp2(node a,node b){
	return a.y-max(a.x,a.z)<b.y-max(b.x,b.z);
}
bool cmp3(node a,node b){
	return a.z-max(a.y,a.x)<b.z-max(b.y,b.x);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		ans=0;
		tot1=tot2=tot3=0;
		for(int i=1;i<=n;i++){
			ai=(node){read(),read(),read()};
			if(check1(ai)) t1[++tot1]=ai;
			else if(check2(ai)) t2[++tot2]=ai;
			else t3[++tot3]=ai;
			ans+=mxx(ai);
		}
		if(tot1>n/2){
			sort(t1+1,t1+tot1+1,cmp1);
			for(int i=1;i<=tot1-n/2;i++){
				ans-=t1[i].x;
				ans+=max(t1[i].y,t1[i].z);
			}
		}
		if(tot2>n/2){
			sort(t2+1,t2+tot2+1,cmp2);
			for(int i=1;i<=tot2-n/2;i++){
				
				ans-=t2[i].y;
				ans+=max(t2[i].x,t2[i].z);
			}
		}
		if(tot3>n/2){
			sort(t3+1,t3+tot3+1,cmp3);
			for(int i=1;i<=tot3-n/2;i++){
				ans-=t3[i].z;
				ans+=max(t3[i].y,t3[i].x);
			}
		}
		we(ans);
	}
	return 0;
}
