#include<bits/stdc++.h>
using namespace std;
const int N=100009;
const int maxn=1e9;
int n;
int ans;
int a[N];//第i号怪物有防御力和攻击力ai
int c[N];//第i号怪物是否发动过攻击 
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for(int i=0;i<n;i++) {
	    cin>>a[i];
		c[i]=0; 
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]!=a[j]&&c[j]==0){
				ans--;
				c[j]=1;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
	}
