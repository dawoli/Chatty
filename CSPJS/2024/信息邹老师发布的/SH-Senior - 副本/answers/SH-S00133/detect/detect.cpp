#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;

int t,n,m,l,vm;
long long d[maxn],v[maxn],a[maxn],p[maxn];

long long ans1[30],ans2[30];

long long ty[maxn];
long long st[maxn];

bool check1(int d1,int v1,int a1){
	double x=0;
	if(a1==0){
		if(v1>vm)return true;
		else if(v1<=vm)return false;
	}
	else if(a1<0){
		if(v1<=vm||p[m]<=d1)return false;	
		else if(v1>vm){
			x=(vm*vm-v1*v1)/(2*a1);
			for(int i=m;i>=1;i--){
				if(x>p[i]-d1&&p[i]>=d1){//
					return true;
				}
			}
			return false;
		}
	}
	else if(a1>0){
		if(v1>=vm)return true;
		else if(v1<vm){
			x=(vm*vm-v1*v1)/(2*a1);
			for(int i=1;i<=m;i++){
				if(x<p[i]-d1&&p[i]>=d1){//
				    return true;
				}
			}
			return false;
		}
	}
}

void check2(int d1,int v1,int a1,int num){
	double x=0;
	int sol1=-1,sol2=-1;
	//
	if(a1==0){
		ty[num]=2;
		st[num]=1;
	}
	//
	else if(a1<0){
		if(v1<=vm){
			ty[num]=2;
		    st[num]=1;
		}
		else if(v1>vm){
			x=(vm*vm-v1*v1)/(2*a1);
			for(int i=m;i>=1;i--){
				if(x>p[i]-d1&&p[i]>=d1){//
					sol1=i;
					break;
				}
			}
			if(sol1==-1){
				ty[num]=2;
		        st[num]=1;
			}
			else{
				ty[num]=1;
				st[num]=sol1;
			}
		}
			
	}
	else if(a1>0){
		if(v1>=vm){
			ty[num]=2;
		    st[num]=1;
		}
		else if(v1<vm){
			x=(vm*vm-v1*v1)/(2*a1);
			for(int i=1;i<=m;i++){
				if(x<p[i]-d1&&p[i]>=d1){//
					sol2=i;
					break;
				}
			}
			if(sol2==-1){
				ty[num]=2;
		        st[num]=1;
			}
			else{
				ty[num]=2;
				st[num]=sol2;
			}
		}
	}
}



int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>l>>vm;
		for(int j=1;j<=n;j++){
			cin>>d[j]>>v[j]>>a[j];
		}
		for(int j=1;j<=m;j++){
			cin>>p[j];
		}
		
		for(int j=1;j<=n;j++){
			if(check1(d[j],v[j],a[j])){
			    ans1[i]++;
			}
		}
		for(int j=1;j<=n;j++){
			check2(d[j],v[j],a[j],j);
		}
		long long ma=-1,mi=1e9;
		for(int j=1;j<=n;j++){
		    if(ty[j]==1){
		    	mi=min(mi,st[j]);
			}
			else if(ty[j]==2){
				ma=max(ma,st[j]);
			}
		}
        ans2[i]=m-(mi-ma+1);
	}
	for(int i=1;i<=t;i++){
		cout<<ans1[i]<<" "<<ans2[i]<<endl;
	}
	return 0;
} 
