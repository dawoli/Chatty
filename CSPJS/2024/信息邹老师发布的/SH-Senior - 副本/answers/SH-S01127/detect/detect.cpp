#include<bits/stdc++.h>

using namespace std;

int n,m,l,ans,qwqwq,times;
long long V,v;
 
int MAIN(){
	ans = 0;
	cin>>n>>m>>l>>V;
	for(int i = 1;i <= n;i++) {
		cin>>qwqwq>>v>>qwqwq;
		if(v>V){
			ans++;
		}
		//ans += v>V?1:0; 
	}
	for(int i = 1;i <= m;i++) {
		cin>>qwqwq;
	}
	qwqwq = !ans?m:m-1;
	cout<<ans<<' '<<qwqwq<<endl;
	
	return 0;	
} 

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>times;
	for(int i = 1;i<= times;i++) {
		MAIN();
	}
	return 0;
}
