#include<bits/stdc++.h>
using namespace std;
struct node{
	int c,bl,q,len,id;
}qu[400005];
struct node2{
	int qq,hh;
};
int t,ans2;
int n,m,l,v,ans;
int p[100005];
int a[100005][5];
int pb[100005];
node2 ji[100005];
node2 jie[100005];
bool cmp(node x,node y){
	if(x.len==y.len){
		return x.c<y.c;
	}
	return x.len<y.len;
}
bool cmp2(node2 x,node2 y){
	return x.hh<y.hh;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		int cnt=0;
		memset(a,0,sizeof(a));
		memset(qu,0,sizeof(qu));
		memset(ji,0,sizeof(ji));
		memset(jie,0,sizeof(jie));
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
			cnt++;
			qu[cnt].id=i;
			qu[cnt].c=0;
			qu[cnt].bl=0;
			qu[cnt].q=0;
			qu[cnt].len=p[i];
		}
		for(int i=1;i<=n;i++){
			int dd=a[i][1];
			int vv=a[i][2];
			int aa=a[i][3];
			if(aa==0){
			if(vv>v){
				ans++;
				cnt++;
				qu[cnt].c=i;
				qu[cnt].bl=1;
				qu[cnt].q=2;
				qu[cnt].len=dd-1;
				cnt++;
				qu[cnt].c=i;
				qu[cnt].bl=2;
				qu[cnt].q=1;
				qu[cnt].len=l+1;
			}
		}else if(aa>0){
			int dn=(v*v-vv*vv)/(2*aa);
			if(dn+dd<l || (dn+dd==l&&(v*v-vv*vv)%(2*aa)==0)){
				ans++;
				cnt++;
				qu[cnt].c=i;
				qu[cnt].bl=1;
				qu[cnt].q=2;
				qu[cnt].len=dn+dd-1;
				cnt++;
				qu[cnt].c=i;
				qu[cnt].bl=2;
				qu[cnt].q=1;
				qu[cnt].len=l+1;
			}
		}else if(aa<0){
			int dn=(v*v-vv*vv)/(2*aa);
			if(vv>v){
				ans++;
				cnt++;
				qu[cnt].c=i;
				qu[cnt].bl=1;
				qu[cnt].q=2;
				qu[cnt].len=dd-1;
				cnt++;
				qu[cnt].c=i;
				qu[cnt].bl=2;
				qu[cnt].q=1;
				qu[cnt].len=dn+dd+1;
			}
		}
		}
		sort(qu+1,qu+1+cnt,cmp);
		int qid=0;
		for(int i=1;i<=cnt;i++){
			if(qu[i].c==0){
				qid=qu[i].id;	
			}
			if(qu[i].c!=0){
				if(qu[i].q==1){
					if(qid!=0){
						if(p[qid]<qu[i].len){
							if(qu[i].bl==1){
								ji[qu[i].c].qq=qid;
							}else ji[qu[i].c].hh=qid;
						}else if(qid>1){
							if(qu[i].bl==1){
								ji[qu[i].c].qq=qid;
							}else ji[qu[i].c].hh=qid;
						}
						
					}
				}else if(qu[i].q==2){
					if(qid<m){
						if(p[qid+1]>qu[i].len){
							if(qu[i].bl==1){
								ji[qu[i].c].qq=qid+1;
							}else ji[qu[i].c].hh=qid+1;
						}else if(qid<m-1){
							if(qu[i].bl==1){
								ji[qu[i].c].qq=qid+2;
							}else ji[qu[i].c].hh=qid+2;
						}
					}
				}
			}
		}
		ans=0;
		cnt=0;
		for(int i=1;i<=n;i++){
			if(ji[i].qq!=0 &&ji[i].hh!=0 && ji[i].qq<=ji[i].hh){
				cnt++;
				ans++;
				jie[cnt].qq=ji[i].qq;
				jie[cnt].hh=ji[i].hh;
			}
		}
		sort(jie+1,jie+1+cnt,cmp2);
		qid=0;
		ans2=0;
		for(int j=1;j<=cnt;j++){
			if(jie[j].qq>jie[qid].hh){
				ans2++;
				qid=j;
			}
		}
		cout<<ans<<" "<<m-ans2<<"\n";
	}
	return 0;
}

