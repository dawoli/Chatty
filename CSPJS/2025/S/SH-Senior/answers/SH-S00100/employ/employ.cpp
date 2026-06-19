#include<bits/stdc++.h>
using namespace std;
int m,n,give_up,last,a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	last=n;
	bool flag=false;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			give_up++;
			last--;
			flag=true;
			a[i]=-1;
		}
	}
	while(true){
		flag=false;
		for(int i=1;i<=n;i++){
			if(a[i]!=-1&&a[i]<=give_up){
				give_up++;
				flag=true;
				last--;
				a[i]=-1;
				
			}
		}
		if(flag==false)break;
	}
	int ans=1;
	cout<<last;
	for(int i=2;i<=last;i++){
		ans*=i;
	}cout<<ans;
	return 0;
}

