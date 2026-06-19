#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n;
string vis[15];
int main(){
	freopen("poker.in","w",stdin);
	freopen("poker.out","r",stdout);
	cin>>n;
	int rep=0;
	for(int i=1;i<=n;i++){
		cin>>vis[i];
	}
	sort(vis+1,vis+n+1);
	for(int i=2;i<=n;i++){
		if(vis[1][i]==vis[1][i-1] and vis[2][i]==vis[2][i-1]){ 
			rep++;
		}
	}
	cout<<52-n+rep<<endl;
	return 0;
}
