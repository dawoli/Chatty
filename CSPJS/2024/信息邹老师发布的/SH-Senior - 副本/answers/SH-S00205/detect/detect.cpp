#include<bits/stdc++.h>
using namespace std;
int s=0;
int T,n,m,l,v,a[100010];
void input(){
	cin>>n>>m>>l>>v;
	for(int i=1;i<=n;i++) cin>>l>>l>>a[i];
}
void ansA(){
	for(int i=1;i<=n;i++) if(a[i]>v){
    	s++;
	}
	cout<<s<<" "<<m-1<<endl;
}
int main(){
	freopen("detect3.in","r",stdin);
	freopen("detect3.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		input();
		ansA();
	}
	return 0;
}
