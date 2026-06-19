#include<bits/stdc++.h>
#define lb(x) ((x)&(-x))
#define il inline
#define ll long long
using namespace std;
const int N=2e5+10,L=5e6+10;
int n,Q;
string s[N][2],t[N][2];

int b[N],e[N],bb[N],ee[N];

ll hs1[N][2],hs2[N][2];

const ll mod1=998244389,mod2=1000000009;

bool flgb=1;

struct qwq{
	int c,l,r,lst;
}ss[N],tt[N];

bool cmp(qwq x,qwq y){
	if(x.c!=y.c)return x.c<y.c;
	else return x.l!=y.l?x.l<y.l:x.r<y.r;
}

struct ttt{
	int t[L];
	il void add(int x,int y){while(x<L){t[x]+=y;x+=lb(x);}}
	il int sum(int x){int res=0;while(x){res+=t[x];x-=lb(x);}return res;}
}tc;


int ans[N];

//For:70pts

int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		b[i]=-1;e[i]=-1;
	}
	for(int i=1;i<=Q;i++){
		cin>>t[i][0]>>t[i][1];
	}
	for(int i=1;i<=n;i++){
		int cntb1=0,cntb2=0;
		for(int j=0;j<s[i][0].length();j++){
			if(s[i][0][j]>'b')flgb=0;
			if(s[i][0][j]=='b')cntb1++;
			if(s[i][1][j]>'b')flgb=0;
			if(s[i][1][j]=='b')cntb2++;
			if(s[i][0][j]!=s[i][1][j]){
				if(b[i]==-1)b[i]=j;
				e[i]=j;
			}
		}
		if(cntb1!=1 || cntb2!=1)flgb=0;
	}
	if(flgb){
		for(int i=1;i<=Q;i++){
			int cntb1=0,cntb2=0;
			for(int j=0;j<t[i][0].length();j++){
				if(t[i][0][j]>'b'){flgb=0;break;}
				if(t[i][0][j]=='b')cntb1++,bb[i]=j;
			}
			if(cntb1!=1 || cntb2!=1){flgb=0;break;}
			
			for(int j=0;j<t[i][1].length();j++){
				if(t[i][1][j]>'b'){flgb=0;break;}
				if(t[i][1][j]=='b')cntb2++,ee[i]=j;
			}
			if(cntb1!=1 || cntb2!=1){flgb=0;break;}
		}
	}
	
	
	if(flgb){
		for(int i=1;i<=n;i++){
			if(s[i][0][b[i]]=='b')ss[i].c=e[i]-b[i];
			else ss[i].c=b[i]-e[i];
			ss[i].l=b[i],
			ss[i].r=s[i][0].length()-e[i]-1;
		}
		for(int i=1;i<=Q;i++){
			tt[i].c=ee[i]-bb[i],
			tt[i].l=min(bb[i],ee[i]),
			tt[i].r=t[i][0].length()-max(bb[i],ee[i])-1,
			tt[i].lst=i;
		}
		sort(ss+1,ss+n+1,cmp);
		sort(tt+1,tt+n+1,cmp);
		int nw=ss[1].c,nwn=0;
		for(int i=1;i<=Q;i++){
			if(t[tt[i].lst][0].length()!=t[tt[i].lst][1].length() || tt[i].c<ss[1].c || tt[i].c>ss[n].c){
				ans[tt[i].lst]=0;
				continue;
			}
			if(tt[i].c>nw){
				for(int j=nwn;ss[j].c==ss[nwn].c && j>=1;j--){
					tc.add(ss[j].r,-1);
				}
				while(ss[nwn+1].c<tt[i].c)nwn++;
				nw=ss[nwn+1].c;
			}
			if(nw!=tt[i].c){
				ans[tt[i].lst]=0;
				continue;
			}
			while(ss[nwn+1].l<=tt[i].l){
				tc.add(ss[nwn+1].r,1);
				nwn++;
			}
			ans[tt[i].lst]=tc.sum(tt[i].r);
		}
		for(int i=1;i<=Q;i++)cout<<ans[i]<<'\n'; 
	}
	else{
		for(int i=1;i<=n;i++){
			if(b[i]>=0){
				for(int j=b[i];j<=e[i];j++){
					hs1[i][0]=(hs1[i][0]*31+s[i][0][j]-'a'+1)%mod1;
					hs1[i][1]=(hs1[i][1]*31+s[i][1][j]-'a'+1)%mod1;
					hs2[i][0]=(hs2[i][0]*31+s[i][0][j]-'a'+1)%mod2;
					hs2[i][1]=(hs2[i][1]*31+s[i][1][j]-'a'+1)%mod2;
				}
			}
		}
		for(int i=1;i<=Q;i++){
			if(t[i][0].length()!=t[i][1].length()){
				cout<<"0\n";
				continue;
			}
			int bg=-1,ed=-1;
			for(int j=0;j<t[i][0].length();j++){
				if(t[i][0][j]!=t[i][1][j]){
					if(bg==-1)bg=j;
					ed=j;
				}
			}
			ll h1=0,h2=0,hh1=0,hh2=0;
			for(int j=bg;j<=ed;j++){
				h1=(h1*31+t[i][0][j]-'a'+1)%mod1;
				h2=(h2*31+t[i][0][j]-'a'+1)%mod2;
				hh1=(hh1*31+t[i][1][j]-'a'+1)%mod1;
				hh2=(hh2*31+t[i][1][j]-'a'+1)%mod2;
			}
			for(int j=1;j<=n;j++){
				if(h1==hs1[j][0] && h2==hs2[j][0] && hh1==hs1[j][1] && hh2==hs2[j][1]){
					bool fl=1;
					for(int k=1;k<=b[j];k++){
						if(bg-k<0){
							fl=0;
							break;
						}
						if(t[i][0][bg-k]!=s[j][0][b[j]-k]){
							fl=0;
							break;
						}
					}
					if(!fl)continue;
					for(int k=1;k<=s[j][0].length()-e[j]-1;k++){
						if(ed+k>=t[i][0].length()){
							fl=0;
							break;
						}
						if(t[i][0][ed+k]!=s[j][0][e[j]+k]){
							fl=0;
							break;
						}
					}
					if(fl)ans[i]++;
				}
			}
			cout<<ans[i]<<'\n';
		}
	} 
	return 0;
}
