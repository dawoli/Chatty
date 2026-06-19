#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=2e18;
int T,n,i,ans=INF;
int x[10]={6,2,5,5,4,5,6,3,7,6};
struct node{
	int ze,on,tw,fo,se,ei,w;
}f[100005];
void add(node &a,int b){
	if(b==0)a.ze++;
	else if(b==1)a.on++;
	else if(b==2)a.tw++;
	else if(b==4)a.fo++;
	else if(b==7)a.se++;
	else a.ei++;
	return;
}
int mm(int a,int b){
	int x=a,y=0,aans=a*10+b,z=1;
	if(a==0&&b==0)return INF;
	if(a==0)return b*10;
	if(b==0){
		while(a/z>=10){
			z*=10;
		}
		return (a-a%z)*10+a%z;
	}
	z=10;
	while(x!=0){
		y=a%z;
		x=a-y;
		b*=10;
		aans=min(aans,x*10+b+y);
		z*=10;
	}
	return aans;
}
signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(i=0;i<=100005;i++){
		f[i].w=INF;
	}
	f[2].on=1,f[2].w=1;
	f[3].se=1,f[3].w=7;
	f[4].fo=1,f[4].w=4;
	f[5].tw=1,f[5].w=2;
	f[6].ze=1,f[6].w=0;
	f[7].ei=1,f[7].w=8;
	i=9; 
	while(T--){
		cin>>n;
		if(n<8){
			if(n==6)cout<<6<<endl;
			else if(f[n].w==INF)cout<<-1<<endl;
			else cout<<f[n].w<<endl;
			continue;
		}
		if(n%7==0&&n>=100){
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
			continue;
		}
		if(n%7==1&&n>=100){
			cout<<10;
			for(int i=1;i<=(n-1)/7-1;i++)cout<<8;
			cout<<endl;
			continue;
		}
		for(;i<=n;i++){
			for(int j=0;j<=9;j++){
				if(j==3||j==5||j==6||j==9||x[j]>i)continue;
				if(f[i-x[j]].w==INF)continue;
				if(f[i].w>mm(f[i-x[j]].w,j)){
					f[i]=f[i-x[j]];
					f[i].w=mm(f[i-x[j]].w,j);
					add(f[i],j);
				}
			}
		}
		if(f[n].w<INF){
			cout<<f[n].w<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
