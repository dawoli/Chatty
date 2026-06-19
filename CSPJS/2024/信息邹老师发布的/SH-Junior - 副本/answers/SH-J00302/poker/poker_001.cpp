#include<bits/stdc++.h>
using namespace std;
struct po{
	string s;
};
po a[60];
int ans;
map<string,bool>vis;
int rep=0;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s;
		vis[a[i].s]=true;
	}
	for(int i=1;i<=n;i++){
		if(vis[a[i].s]==true){
			rep++;
			vis[a[i].s]=false;
		}
	}
	ans=52-rep;
	cout<<ans<<endl;
	return 0;
}
