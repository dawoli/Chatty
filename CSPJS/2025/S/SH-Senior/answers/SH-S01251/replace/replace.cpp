#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll BASE=131;
ll n,q,Hval[2009][2009][2],HvalSP[5000009][2];
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') f=((bool)(c^'-')<<1)-1,c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
ll hsh(string s,ll l=0,ll r=-1,ll type=0){
	if(r==-1) r=s.size();
	ll sum=0;
	if(type){
		for(ll i=r-1;i>=l;--i)
			sum=sum*BASE+s[i];
		return sum;
	}
	for(ll i=l;i<r;++i)
		sum=sum*BASE+s[i];
	return sum;
}
map<pair<ll,ll>,ll> mp;
void solveBF(){
	string t[2];
	for(ll i=1;i<=n;++i){
		cin>>t[0]>>t[1];
		++mp[make_pair(hsh(t[0]),hsh(t[1]))];
	}
	for(ll i=1;i<=q;++i){
		cin>>t[0]>>t[1];
		ll len=t[0].size(),L=-1,R=0,ans=0;
		for(ll lft=0;lft<len;++lft){
			Hval[lft][lft][0]=t[0][lft],
			Hval[lft][lft][1]=t[1][lft];
			for(ll rgt=lft+1;rgt<len;++rgt){
				Hval[lft][rgt][0]=Hval[lft][rgt-1][0]*BASE+t[0][rgt],
				Hval[lft][rgt][1]=Hval[lft][rgt-1][1]*BASE+t[1][rgt];
			}
		}
		for(ll j=0;j<len;++j)
			if(t[0][j]^t[1][j])
				L=(L==-1?j:L),R=j;
		for(ll l=0;l<=L;++l)
			for(ll r=R;r<len;++r)
				ans+=mp[make_pair(Hval[l][r][0],Hval[l][r][1])];
		cout<<ans<<"\n";
	}
	exit(0); 
}
string S[200009][2],T[2];
void solveSP(){
	for(ll i=1;i<=n;++i)
		cin>>S[i][0]>>S[i][1];
	for(ll i=1;i<=q;++i){
		cin>>T[0]>>T[1];
		ll LT=-1,RT=0,len=T[0].size();
		for(ll j=0;j<len;++j)
			if(T[0][j]^T[1][j])
				LT=(LT==-1?j:LT),RT=j;
		ll HshA=hsh(T[0],LT,RT+1),HshB=hsh(T[1],LT,RT+1);
		ll cntL=0,cntR=0;
		ll ans=0;
		for(ll i=LT-1;i>=0;--i)//0代表从后往前
			++cntL,
			HvalSP[cntL][0]=HvalSP[cntL-1][0]*BASE+T[0][i];
		for(ll i=RT+1;i<len;++i)
			++cntR,
			HvalSP[cntR][1]=HvalSP[cntR-1][1]*BASE+T[0][i];
		for(ll i=1;i<=n;++i){
			len=S[i][0].size();
			ll L=-1,R=0;
			for(ll j=0;j<len;++j)
				if(S[i][0][j]^S[i][1][j])
					L=(L==-1?j:L),R=j;
			if(L==-1) continue;
//			cout<<i<<":"<<L<<" "<<R<<"\n";
			ll lenL=L,lenR=S[i][0].size()-R-1;
//			cout<<(HshA==hsh(S[i][0],L,R+1))<<" "<<(HshB==hsh(S[i][1],L,R+1,-1))<<" "<<(hsh(S[i][0],0,L)==HvalSP[lenL][0])<<" "<<(hsh(S[i][0],R+1,len)==HvalSP[lenR][1])<<"\n";
			if( HshA==hsh(S[i][0],L,R+1)&&
				HshB==hsh(S[i][1],L,R+1)&&
				hsh(S[i][0],0,L,-1)==HvalSP[lenL][0]&&
				hsh(S[i][0],R+1,len)==HvalSP[lenR][1])
				++ans;
		}
		cout<<ans<<"\n";
	}
	exit(0);
}
struct Ti{
	ll l,r,del,id;//del=nowPos[b]-prePos[b]
}huan[200009],Q[200009];
bool cmpPos(const Ti&a,const Ti&b){
	return a.del<b.del;
}
bool cmpL(const Ti&a,const Ti&b){
	return a.l<b.l;
}
ll LenMa=0,bit[5000009],ansSP[200009];
inline ll LSB(ll x){return x&(-x);}
void add(ll x,ll C){
	while(x<LenMa) bit[x]+=C,x+=LSB(x);
}
ll query(ll x){
	ll ans=0;
	while(x) ans+=bit[x],x-=LSB(x);
	return ans;
}
void solveSP2(){
	for(ll i=1;i<=n;++i){
		cin>>T[0]>>T[1];
		LenMa=max(LenMa,(ll)T[0].size());
		ll prePos=-1,nowPos=-1,Llen=0,Rlen=0;
		for(ll j=0;j<T[0].size();++j){
			if(T[0][j]=='b') prePos=j;
			if(T[1][j]=='b') nowPos=j;
		}
		Llen=min(prePos,nowPos);
		Rlen=T[0].size()-max(prePos,nowPos);
		huan[i]=(Ti){Llen,Rlen,nowPos-prePos,0};
	}
	for(ll i=1;i<=q;++i){
		cin>>T[0]>>T[1];
		LenMa=max(LenMa,(ll)T[0].size());
		ll prePos=-1,nowPos=-1,Llen=0,Rlen=0;
		for(ll j=0;j<T[0].size();++j){
			if(T[0][j]=='b') prePos=j;
			if(T[1][j]=='b') nowPos=j;
		}
		Llen=min(prePos,nowPos);
		Rlen=T[0].size()-max(prePos,nowPos);
		Q[i]=(Ti){Llen,Rlen,nowPos-prePos,i};
	}
	
//	for(ll i=1;i<=q;++i){
//		ll sum=0;
//		for(ll j=1;j<=n;++j)
//			if(Q[i].del==huan[j].del&&Q[i].l>=huan[j].l&&Q[i].r>=huan[j].r)
//				++sum;
//		cout<<sum<<"\n";
//	}
	
	
	
	sort(huan+1,huan+n+1,cmpPos);
	sort(Q+1,Q+q+1,cmpPos);
	for(ll L=1,R=1,LH=1,RH=1;;){
		
		while(R<q&&Q[R+1].del==Q[R].del) ++R;//把R相同的找到一起
		sort(Q+L,Q+R+1,cmpL);
		//这里是问询
		while(RH<n&&huan[RH].del<Q[L].del) ++RH;
		LH=RH;
		while(RH<n&&huan[RH+1].del==Q[L].del) ++RH;
		if(huan[LH].del==Q[L].del){
//			cout<<L<<" "<<R<<" "<<LH<<" "<<RH<<"\n";
			sort(huan+LH,huan+RH+1,cmpL);
			ll iQ=L,iH=LH;
			for(;iQ<=R;++iQ){
				while(iH<=RH&&huan[iH].l<=Q[iQ].l)
					add(huan[iH].r,1),++iH;
				ansSP[Q[iQ].id]=query(Q[iQ].r);
			}
			
		
			for(ll i=LH;i<iH;++i) add(huan[i].r,-1);
		}
		L=R+1,R=L;
		if(L>q) break;
	}
	for(ll i=1;i<=q;++i)
		cout<<ansSP[i]<<"\n";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	if(q==1) solveSP(),exit(0);
	if(n<=1000&&q<=1000) solveBF(),exit(0);
	solveSP2();
	return 0;
}
