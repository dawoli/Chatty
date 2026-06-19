#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,vmax;
struct C{
	int d,v,a,st,ed;
}c[100005];
int detect[100005];
struct Last{
	int st,ed;
}last[100005];
int tot=0;
bool cmp(C a,C b){
	if(a.st==b.st)return a.ed<b.ed;
	else return a.st<b.st;
}
bool baohan(Last x,Last y){
	if(x.st==y.st&&x.ed<=y.ed)return true;
	return false;
}
bool youbing(Last x,Last y){
	if(y.st<=x.ed&&x.ed<=y.ed)return true;
	return false;
}
bool gengxiao(Last x,Last y){
	if(x.st<=y.st&&x.ed>=y.ed)return true;
	return false;
}
bool found_d(int st,int ed){
	if(ed<st)return false;
	if(st>l)return false;
	int lpos=1,rpos=m;
	if(st==detect[1]||st==detect[m]||ed==detect[1]||ed==detect[m])return true;
	while(rpos>lpos){
		int mid=(rpos+lpos)>>1;
		//if(detect[mid]==st||detect[rpos]==st||detect[lpos]==st)return true;
		if(rpos==lpos+1){break;}
		else if(detect[mid]<st){
			lpos=mid+1;
		}else{
			rpos=mid;
		}
	}if(detect[lpos]>=st&&detect[lpos]<=ed)return true;
	if(detect[rpos]>=st&&detect[rpos]<=ed)return true;
	return false;
}
inline int min(int a,int b){
	return a<b?a:b;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		tot=0;
		scanf("%d%d%d%d",&n,&m,&l,&vmax);
		for(int i=1,d,v,a,st,ed;i<=n;i++){
			scanf("%d%d%d",&d,&v,&a);
			if(a==0){
				if(v>vmax)st=d,ed=l;
				else st=l+2,ed=l+1;
			}
			else if(a>0){
				ed=l;
				if(v>vmax)st=d;
				else{
					if((vmax*vmax-v*v)%(2*a)==0)st=((vmax*vmax-v*v)/(2*a))+d+1;
					else st=1+((vmax*vmax-v*v)/(2*a))+d;
				}
			}else{
				st=d;
				if(v<vmax)ed=d-1;
				else{
					if((abs(vmax*vmax-v*v))%(abs(2*a))==0)ed=((vmax*vmax-v*v)/(2*a))+d-1;
					else ed=((vmax*vmax-v*v)/(2*a))+d;
				}
			}
			c[i]=(C){d,v,a,st,ed};
		}for(int i=1;i<=m;i++)
			scanf("%d",&detect[i]);
		sort(detect+1,detect+1+m);
		sort(c+1,c+1+n,cmp);
		int pppos=1,ans1=0;
		if(found_d(c[1].st,c[1].ed)){
			last[++tot]=(Last){c[1].st,c[1].ed};
			ans1++;
		}else{
			while(pppos<=n&&!found_d(c[pppos].st,c[pppos].ed))pppos++;
			if(pppos<=n){last[++tot]=(Last){c[pppos].st,c[pppos].ed};ans1++;}
			else ans1=0;
		}
		for(int i=pppos+1;i<=n;i++){
			if(!found_d(c[i].st,c[i].ed))continue;
			ans1++;Last st=(Last){c[i].st,c[i].ed};
			if(baohan(st,last[tot])){
				continue;
			}else if(gengxiao(last[tot],st)){
				last[tot]=st;continue;
			}else if(youbing(last[tot],st)){
				if(found_d(c[i].st,last[tot].ed)){
					last[tot].st=c[i].st;
				}else{
					last[tot].ed=c[i].st-1;
					Last tmp=(Last){last[tot].ed+1,c[i].ed};
					last[++tot]=tmp;
				}continue;
			}else{
				last[++tot]=(Last){c[i].st,c[i].ed};
			}
		}
		printf("%d %d\n",ans1,m-tot);
	}
	return 0;
}

