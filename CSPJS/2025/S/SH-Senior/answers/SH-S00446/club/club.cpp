#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
//对于每个成员先平分 然后根据去另外两组的收益交换/更改组 
int T,n,A,B,C,ans;
struct Node{
	int x,y,z,v=0;
}a[N];
vector<int> x,y,z;
bool cmpa(Node f,Node w){
	return f.x>w.x;
}
bool cmpx(int f,int w){
	return a[f].x>a[w].x;
}
bool cmpy(int f,int w){
	return a[f].y>a[w].y;
}
bool cmpz(int f,int w){
	return a[f].z>a[w].z;
}
void solvea(){
	sort(a+1,a+n+1,cmpa);
	for(int i=1;i<=n/2;i++){
		ans+=a[i].x;
	}
	cout<<ans<<endl;
	return ;
}
void solve(){
	
	for(int i=1;i<=n;i++){
		if(i<n/3){
			x.push_back(i);
			ans+=a[i].x;
		}
		else if(i>=n/3&&i<n/3*2){
			y.push_back(i);
			ans+=a[i].y;
		}
		else{
			z.push_back(i);
			ans+=a[i].z;
		}
	}
	sort(x.begin(),x.end(),cmpx);
	sort(y.begin(),y.end(),cmpy);
	sort(z.begin(),z.end(),cmpz);
	
	for(int i=0;i<x.size();i++){
		int v=x[i];
		
	}
	cout<<0;
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1,u,b,c;i<=n;i++){
			cin>>u>>b>>c;
			a[i].x=u;a[i].y=b;a[i].z=c;
			if(b==0&&c==0){
				A++;
			}
		}
		
		if(A==n){
			solvea();
		}else{
			A=0;
			solve();
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
