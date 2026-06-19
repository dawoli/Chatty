#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,L,V,d[100000+10],v[100000+10],a[100000+10],p[100000+10],cnt=0,ls[100000+10];
int read(){
	char c;int ret=0;bool mode=0;
	c=getchar();
	if(c=='-'){
		mode=1;
		c=getchar(); 
	} 
	while(c<='9'&&c>='0'){
		ret*=10;ret+=c-'0';
		c=getchar();
	}
	return (mode?-ret:ret);
}
void solve(){
	cnt=0;
	memset(ls,0,sizeof(ls));
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >Q,Q2,Q2f,st;
	n=read(),m=read(),L=read(),V=read();
	int sqV=V*V;
	for(int i=1;i<=n;i++){
		d[i]=read(),v[i]=read(),a[i]=read(); 
		if(v[i]<=V&&a[i]<=0)cnt++;
		else if(a[i]==0){
			Q.push(make_pair(d[i],i));
		}else if(a[i]<0){
			int dis=d[i]+(int)(ceil((double)((sqV-v[i]*v[i])>>1))/(double)a[i]);
			Q2f.push(make_pair(d[i],i));
			Q2.push(make_pair(dis,i));
		}else{
			int dis=d[i]+(int)(ceil((double)((sqV-v[i]*v[i])>>1))/(double)a[i]);
			Q.push(make_pair(dis,i));
		}
	}
	for(int i=1;i<=m;i++){
		p[i]=read();
		while(!Q.empty()&&Q.top().first<=p[i]){
			st.push(make_pair(i,m)); 
			Q.pop();
		}
		while(!Q2f.empty()&&Q2f.top().first<p[i]){
			ls[Q2f.top().second]=i;
			Q2f.pop();
		}
		while(!Q2.empty()&&Q2.top().first<p[i]){
			if(ls[Q2.top().second]&&ls[Q2.top().second]<=i-1){
				st.push(make_pair(ls[Q2.top().second],i-1)); 
			}
			else cnt++;
			Q2.pop();
		}
	}
	while(!Q2.empty()){
		if(ls[Q2.top().second]){
			st.push(make_pair(ls[Q2.top().second],m));
		}
		Q2.pop();
	}
	cnt+=Q.size()+Q2f.size();
	cout<<n-cnt<<" ";
	if(st.empty()){
		cout<<0<<endl;
		return ;
	}
	if(st.size()==1){
		cout<<1<<endl;
		return;
	}
	int lll=st.top().first,rrr=st.top().second,ans=1;st.pop();
	bool mode=0;
	while(!st.empty()){
		int lst=st.top().first,rst=st.top().second;
		st.pop();
		if(lst<=rrr)lll=lst,rrr=min(rst,rrr),mode=0;
		else ans++,lll=lst,rrr=rst,mode=1;
	}
	cout<<m-ans<<endl;
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout); 
	t=read();
	while(t--){
		solve();
	}
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
*/
