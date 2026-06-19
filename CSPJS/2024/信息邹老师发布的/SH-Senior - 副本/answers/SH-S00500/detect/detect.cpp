#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5,_L=1e6+5;

int n,m,L,V,T;
int p[N],d[N],v[N],a[N];

struct seg{
	int st,sp;
}s[N];

int t[_L],Tag=0,tag[_L];

inline int lowbit(int x){
	return x&(-x);
}

void upd(int p){
	p++;
	while(p<=L){
		if(tag[p]!=Tag)t[p]=0;
		tag[p]=Tag;
		t[p]++;
		p+=lowbit(p);
	}
}

int chek(int p){
	p++;
	int res=0;
	while(p>0){
		if(tag[p]!=Tag)t[p]=0;
		tag[p]=Tag;
		res+=t[p];
		p-=lowbit(p);
	}
	return res;
}

inline int chk(int l,int r){
	return chek(r)-chek(l-1);
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for(int i=0;i<n;i++)cin>>d[i]>>v[i]>>a[i];
		for(int i=0;i<m;i++)cin>>p[i];
		sort(p,p+m);
		int cnt=0;
		int c=0;
		for(int i=0;i<n;i++){
			if(d[i]>p[m-1])continue;
			auto _nxtp=lower_bound(p,p+m,d[i]);
			int nxtp=_nxtp-p;
			if(a[i]>0){
				if(v[i]>V){
					cnt++;
					s[c].st=nxtp;s[c].sp=m-1;
					c++;
					continue;
				}
				int dis=p[m-1]-d[i];
				int sqmax=v[i]*v[i]+2*a[i]*dis;
				if(sqmax>V*V)cnt++;
				
//				double safetim=(V-v[i])/((double)a[i]);
//				int vtim=ceil(safetim);
//				if(safetim==vtim)vtim++;
//				int vdis=v[i]*vtim+ceil(0.5*a[i]*vtim*vtim);
				double vtim=(V-v[i])/((double)a[i]);
				double vdis=v[i]*vtim+0.5*a[i]*vtim*vtim;
				int vp=lower_bound(p,p+m,ceil(vdis)+d[i])-p;
				if(vp==m)continue;
				s[c].st=vp;s[c].sp=m-1;
				c++;
			}
			else if(a[i]==0){
				if(v[i]>V){
					cnt++;
					s[c].st=nxtp;s[c].sp=m-1;
					c++;
				}
			}
			else{
				if(v[i]<=V)continue;
				int dis=p[nxtp]-d[i];
				int sqmax=v[i]*v[i]+2*a[i]*dis;
				if(sqmax>V*V)cnt++;
				
//				int stim=ceil((V-v[i])/((double)a[i]));
//				int sdis=v[i]*stim+ceil(0.5*a[i]*stim*stim);
//				int _sp=lower_bound(p,p+m,sdis+d[i])-p;
//				int vp=_sp-1;
				double vtim=(V-v[i])/((double)a[i]);
				double vdis=v[i]*vtim+0.5*a[i]*vtim*vtim;
				int vp=lower_bound(p,p+m,ceil(vdis)+d[i])-p-1;
				if(vp<nxtp)continue;
				s[c].st=nxtp;s[c].sp=vp;
				c++;
			}
		}
		cout<<cnt<<' ';
		
		Tag++;
		
		map<int,vector<int>> ends;
		
		for(int i=0;i<c;i++)ends[s[i].sp].push_back(i);
		
		int minv=0;
		
		for(auto& sp:ends){
			for(int id:sp.second){
				if(chk(s[id].st,s[id].sp))continue;
				minv++;
				upd(sp.first);
			}
		}
		cout<<m-minv<<endl;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

