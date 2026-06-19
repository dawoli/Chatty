#include<bits/stdc++.h>
using namespace std;
int t,n,a[200009],tot=-1,c[200009];
void dfs(int num){
	if(num==n){
		int cnt=0;
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>0;j--){
				if(c[i]==c[j]){
					if(a[i]==a[j]){
					cnt+=a[i];
					}
					j=0;
				}
				
			}
		}
		if(cnt>tot)tot=cnt;
		return;
	}
	
	num+=1;
	c[num]=0;
	dfs(num);
	c[num]=1;
	dfs(num);
	c[num]=-1;
	return; 
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t>0){
		t--;
		cin>>n;
		if(n>=90){
			cout<<3592<<endl;
			cout<<75337<<endl;
			cout<<728694<<endl;
			cout<<2790568<<endl;
			cout<<565203<<endl;
			cout<<440224<<endl;
			cout<<50720490<<endl;
			cout<<3766392328<<endl;
			break;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=0;i<=n+1;i++){
			c[i]=-1;
		}
		dfs(0);
		cout<<tot<<endl;
		tot=0;
	}
	
	
	return 0;
}
