#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,int>M;
string s1[200911],s2[200911],t1[200911],t2[200911];
int N,Q,L,mx,c[200911],f[200911],ans[200911],cnt1,cnt2;
struct st{
	int delta,x,y,id;
}d[200911],e[200911];
int qu(int x){int r=0;
	for(;x;x-=x&-x)r+=c[x];
	return r;
}void ad(int x,int e){
	for(;x<=mx;x+=x&-x)c[x]+=e;
}st gt(string&s,string&t,int id){
	int l=0,r=0;
	for(;l<=s.size();l++)if(s[l]=='b')break;
	for(;r<=s.size();r++)if(t[r]=='b')break;
	st ret;ret.delta=r-l;ret.x=min(l,r)+1;ret.y=s.length()-max(l,r);ret.id=id;
	if(s.length()!=t.length())ret.delta=1e9+7;
	return ret;
}int go(int siz,char c,char d,string&s,string&t){
	if(c==s[siz]&&d==t[siz])return siz+1;
	else if(siz>0)return go(f[siz],c,d,s,t);
	else return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>N>>Q;
	for(int i=1;i<=N;i++)cin>>s1[i]>>s2[i],mx=max(mx,int(s1[i].length())),mx=max(mx,int(s2[i].length()));
	for(int i=1;i<=Q;i++)cin>>t1[i]>>t2[i],L+=(t1[i].length()+t2[i].length()),mx=max(mx,int(t1[i].length())),mx=max(mx,int(t2[i].length()));
	if(Q==1||L<=2000){
		for(int i=1;i<=N;i++){
			memset(f,0,sizeof f);
			memset(c,0,sizeof c);
			cnt1=cnt2=0;
			f[1]=0;for(int j=1;j<s1[i].length();j++)f[j+1]=go(f[j],s1[i][j],s2[i][j],s1[i],s2[i]);
			for(int k=1;k<=Q;k++){
				for(int j=1;j<=t1[k].length();j++){
					c[j]=go(c[j-1],t1[k][j-1],t2[k][j-1],t1[k],t2[k]);
					if(c[j]==s1[i].length())ans[k]++;
				}
			}
		}for(int i=1;i<=Q;i++)cout<<ans[i]<<endl;
	}else{
		for(int i=1;i<=N;i++)d[i]=gt(s1[i],s2[i],i);//,cout<<d[i].delta<<' '<<d[i].x<<" "<<d[i].y<<endl;
		for(int i=1;i<=Q;i++)e[i]=gt(t1[i],t2[i],i);
		sort(d+1,d+1+N,[](st a,st b){return (a.delta==b.delta)?(a.y<b.y):(a.delta<b.delta);});
		sort(e+1,e+1+Q,[](st a,st b){return (a.delta==b.delta)?(a.y<b.y):(a.delta<b.delta);});
		int i=1,j=1;
		while(i<=N&&j<=Q){
			while(d[i].delta<e[j].delta&&i<=N)i++;
			while(d[i].delta>e[j].delta&&j<=Q)j++;
			if(i>N||j>Q)break;
			memset(c,0,sizeof c);
			int delta=d[i].delta;
			for(;j<=Q&&e[j].delta==delta;j++){
				while(i<=N&&d[i].delta==delta&&d[i].y<=e[j].y)ad(d[i].x,1),i++;
				ans[e[j].id]=qu(e[j].x);
			}
		}for(int i=1;i<=Q;i++)cout<<ans[i]<<endl;
	}
}
