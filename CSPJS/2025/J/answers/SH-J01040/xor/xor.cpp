#include<bits/stdc++.h> 
using namespace std;
string a[500005], q[500005]; 
string k;
int n,cnt,ans;
long long x;
bool stop[500005];
int sto[500005];
struct node{
	int u,v;
};
node e[500005];
void convert(long long m, string &b){
	int t;
	while(m!=0){
		t=m%2;
		if(t==0){
			b+='0';
		} else{
			b+='1';
		}
		m=m/2;
	}
	return;
}
string xo(string c, string d){
	string b;
 	if(d.length()==0){
 		b=c;
 		return b;
	 }
	 int ma=min(d.length(), c.length());
	 for(int i=0; i<ma; i++){
	 	if(d[i]==c[i]){
	 		if(ma==c.length()){
	 			d[i]='0';
			 } else{
			 	c[i]='0';
			 }
		 } else{
		 	if(ma==c.length()){
		 		d[i]='1';
			 } else{
			 	c[i]='1';
			 }
		 }
	 }
	 if(ma<c.length()){
	 	b=c;
	 } else{
	 	b=d;
	 }
 	return b;
 }
int dfs(int start, int cn){
	int an=cn;
	for(int i=1; i<=cnt; i++){
		if(e[i].u==start && i!=start){
			for(int end=e[i].v; end<=cnt; end++){
				if(stop[end]==false){
					an=max(an,dfs(end,cn+1));
				} else{
					an=max(an,sto[end]);
				}
			}
		}
	}
	stop[start]=true;
	sto[start]=an;
	return an;
}
int main(){
	freeopen("xor.in","r","stdin");
	freeopen("xor.out","w","stdout");
	cin>>n>>x;
	convert(x, k);
	for(int i=1; i<=n; i++){
		cin>>x;
		convert(x,a[i]);
		q[i]=xo(a[i],q[i-1]); 
	}
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			if(xo(q[j],q[i-1])==k){
				cnt++;
				e[cnt].u=i;
				e[cnt].v=j;
			}
		}
	}
	for(int i=1; i<=cnt; i++){
		ans=max(ans,dfs(e[i].u,1));
	}
	cout<<ans;
	return 0;
}
