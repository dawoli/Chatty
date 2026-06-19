#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,V,ans;
int d[100009],v[100009],a[100009],p[100009];
double dis;
bool all0(){
	for(int i=1;i<=n;i++){
		if(a[i]!=0) return false;
	}
	return true;
}
int solve0(){
	for(int i=1;i<=n;i++){
		if(d[i]>p[n]){
			return 0;
		} 
	}
	return n-1;
}
int allp(){
	for(int i=1;i<=n;i++){
		if(a[i]<=0) return false;
	}
	return true;
}
int solvep(){
	for(int i=1;i<=n;i++){
		dis=(V*V-v[i]*v[i])/(2*a[i]);
		if(ceil(dis)+d[i]>p[n]) return 0; 
	}
	return n-1;
}
int alln(){
	for(int i=1;i<=n;i++){
		if(a[i]>=0) return false;
	}
	return true;
}
int solven(){
	for(int i=1;i<=n;i++){
		dis=(V*V-v[i]*v[i])/(2*a[i]);
		if(ceil(dis)+d[i]>p[n]) return 0; 
	}
	return n-1;
}
int solvebf(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			
		}
	}
	return n-3;
}
int solve(){
	return 0;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]>V&&d[i]<=p[m]) ans++;
			}
			else{
				dis=(V*V-v[i]*v[i])/(2*a[i]);
				if(a[i]>0&&(dis+d[i])<=p[m]) ans++;
				else{
					for(int j=1;j<=m;j++){
						if((p[j]>=d[i])&&p[j]<int(floor(dis))+d[i]){
							ans++; 
							break;
						}
					}
				}
			}
		}
		cout<<ans<<" ";
		if(n<=10) cout<<solvebf()<<endl;
		else if(all0) cout<<solve0()<<endl;
		else if(allp) cout<<solvep()<<endl;
		else if(alln) cout<<solven()<<endl;
		else cout<<solve()<<endl;
	}
	return 0;
} 
