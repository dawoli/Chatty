#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,L,vlim,cnt;
const int MAXN=1e5+5;
struct node{
	int d,v,a;
}car[MAXN];
int p[MAXN];
struct Node{
	int l,r;
}isneed[MAXN];
bool check(int mid,int st,int ed,int v,int a){
	return p[mid]>=st&&p[mid]<=ed&&sqrt(2*a*(p[mid]-st)+v*v)>vlim;
}
inline int read(){
	int sum=0;
	int fg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	return sum*fg;
}
int find1(int st,int v,int a,int ed){
	//a>=0 测速器越往前，越靠近其起点，得到第一个测得其超速的测速器 
	int le=1,ri=m;
	int mid=(le+ri)>>1;
	int ans=0;
	while(le<=ri){
		mid=(le+ri)>>1;
		if(check(mid,st,ed,v,a)){
			ri=mid-1,ans=mid;
		}else{
			if(p[mid]>ed)ri=mid-1;
			else le=mid+1;
		}
	}
	return ans; 
}
int find2(int st,int v,int a,int ed){
	//a<0 测速器越往后，越靠近其终点，得到最后一个测得其超速的测速器 
	int le=1,ri=m;
	int mid=(le+ri)>>1;
	int ans=0;
	while(le<=ri){
		mid=(le+ri)>>1;
		if(check(mid,st,ed,v,a)){
			le=mid+1;ans=mid;
		}else{
			if(p[mid]<st)le=mid+1;
			else ri=mid-1;
		}
	}
	return ans; 
}
int find3(int ed){
	int le=1,ri=m;
	int mid=(le+ri)>>1;
	int ans=0;
	while(le<=ri){
		mid=(le+ri)>>1;
		if(p[mid]<=ed){
			le=mid+1;ans=mid;
		}else{
			ri=mid-1;
		}
	}
	return ans;
}
int find4(int st){
	int le=1,ri=m;
	int mid=(le+ri)>>1;
	int ans=0;
	while(le<=ri){
		mid=(le+ri)>>1;
		if(p[mid]>=st){
			ri=mid-1;ans=mid;
		}else{
			le=mid+1;
		}
	}
	return ans;
}
bool cmp(Node u,Node v){
	return u.l<v.l;
}
inline int print(int num){
	if(num<0)putchar('-'),num=-num;
	if(num>9)print(num/10);
	putchar(num%10+'0');
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		//memset(car,0,sizeof(car));
		memset(isneed,0,sizeof(isneed));
		//memset(p,0,sizeof(p));
		cnt=0;
//		cin>>n>>m>>L>>vlim;
        n=read(),m=read();
        L=read(),vlim=read();
		for(int i=1;i<=n;i++){
			car[i].d=read();
			car[i].v=read();
			car[i].a=read();
		}
		for(int i=1;i<=m;i++){
			p[i]=read();
		}
		for(int i=1;i<=n;i++){
			int d=car[i].d,v=car[i].v,a=car[i].a;
			int ed;
			//d为起点，v为初速度，a为加速度 
//			int s=(v*v)/(2*a);
//			int ed=s+d;
            if(a<0){
            	ed=d+(v*v)/(2*abs(a));
			}else{
				ed=L;
			}
			//ed为终点 
			if(ed>L)ed=L;
			if(a>=0){
				int id=find1(d,v,a,ed);
				//find为最靠近终点的一个测速器的编号 
				if(id==0){//这辆车不超速 
					
				}else{//这辆车超速 
					++cnt;
					isneed[cnt].l=id;
					isneed[cnt].r=find3(ed);//p[k]<=ed,find3
				}
			}else{
				int id=find2(d,v,a,ed);
				if(id==0){
					
				}else{
					++cnt;
					isneed[cnt].l=find4(d);//p[k]>=st,find4
					isneed[cnt].r=id;
				}
			}
		}
		sort(isneed+1,isneed+1+cnt,cmp);
		int num=0;
		int lim=isneed[1].r;
		for(int i=1;i<=cnt;i++){
			if(i==1){
				++num;
				continue;
			}
			if(isneed[i].l<=lim){
				lim=min(lim,isneed[i].r);
				continue;
			}
			else ++num,lim=isneed[i].r;
		}
//		cout<<cnt<<" "<<m-num<<"\n";
        print(cnt);cout<<" ";
        print(m-num);cout<<"\n";
	}
	return 0;
}
