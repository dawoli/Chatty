#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int t,n,a[maxn],color[maxn];
struct cp{
	int l,r,num;
};
bool cmp(cp a,cp b){
	return a.num>b.num;
}
void su(){
	for(int i=0;i<maxn;i++){
		a[i]=0;
		color[i]=0;
	}
//	memset(a,0,maxn);
//	memset(color,0,maxn);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
cin>>t;
while(t--){
	cin>>n;
	su();
	long long ans=0;
	map<int,int> m;
	vector<cp> vt;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(m[a[i]]!=0){
			cp tmp;
			tmp.l=m[a[i]];
			tmp.r=i;
			tmp.num=a[i];
			vt.emplace_back(tmp);
		}
		m[a[i]]=i;
	} 
	sort(vt.begin(),vt.end(),cmp);
//	
//	for(cp i:vt){
//		cerr<<"l:"<<i.l<<" r:"<<i.r<<" num:"<<i.num<<endl;
//	}
//	for(int i=0;i<n;i++){
//		cerr<<color[i]<<" ";
//	}	cerr<<endl;
//	
	for(cp i : vt){
		if(color[i.l]==color[i.r]&&color[i.l]==0){
			bool b=1;
			for(int j=i.l+1;j<i.r;j++){
				if(color[j]!=0){
					b=0;
					break;
				}
			}
			if(b){
				color[i.l]=1;
				color[i.r]=1;
				for(int j=i.l+1;j<i.r;j++){
					color[j]=-1;
				}
				ans+=i.num;
			}
		}else if(color[i.l]==color[i.r]&&color[i.l]==-1){
			bool b=1;
			for(int j=i.l+1;j<i.r;j++){
				if(color[j]!=0){
					b=0;
					break;
				}
			}
			if(b){
				color[i.l]=1;
				color[i.r]=1;
				for(int j=i.l+1;j<i.r;j++){
					color[j]=-1;
				}
				ans+=i.num;
			}
		}else if(color[i.l]==1&&color[i.r]==0){
			bool b=1;
			for(int j=i.l+1;j<i.r;j++){
				if(color[j]!=0){
					b=0;
					break;
				}
			}
			if(b){
				color[i.l]=1;
				color[i.r]=1;
				for(int j=i.l+1;j<i.r;j++){
					color[j]=-1;
				}
				ans+=i.num;
			}
		}else if(color[i.l]==0&&color[i.r]==1){
			bool b=1;
			for(int j=i.l+1;j<i.r;j++){
				if(color[j]!=0){
					b=0;
					break;
				}
			}
			if(b){
				color[i.l]=1;
				color[i.r]=1;
				for(int j=i.l+1;j<i.r;j++){
					color[j]=-1;
				}
				ans+=i.num;
			}
		}else if(color[i.l]==0&&color[i.r]==-1){
			bool b=1;
			for(int j=i.l+1;j<i.r;j++){
				if(color[j]!=0){
					b=0;
					break;
				}
			}
			if(b){
				color[i.l]=1;
				color[i.r]=1;
				for(int j=i.l+1;j<i.r;j++){
					color[j]=-1;
				}
				ans+=i.num;
			}
		}else if(color[i.l]==-1&&color[i.r]==0){
			bool b=1;
			for(int j=i.l+1;j<i.r;j++){
				if(color[j]!=0){
					b=0;
					break;
				}
			}
			if(b){
				color[i.l]=1;
				color[i.r]=1;
				for(int j=i.l+1;j<i.r;j++){
					color[j]=-1;
				}
				ans+=i.num;
			}
		}
		
//		cerr<<ans<<endl; 
		
	}
	cout<<ans<<endl;
}
	return 0;
}
/*
3
3
1 2 1
4
1 2 3 4
8
3 5 2 5 1 2 1 4

1
0
8

1
15
1 12 11 11 7 11 15 6 4 6 3 15 7 5 2

37

10
15
5 3 7 2 4 13 11 6 5 5 3 5 12 8 13
15
1 12 11 11 7 11 15 6 4 6 3 15 7 5 2
*/
