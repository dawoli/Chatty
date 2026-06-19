#include<bits/stdc++.h>
using namespace std;
const int N=500006;
int a[N],n,k,ans,m;
int ial[N],jal[N];
void solve(const int &v,const int &f,const int &b){
	if(f<=b){
		int e1=v^f;
		int e2=v|f;
		int e3=v&f;
		solve(e1,f+1,b);
		solve(e2,f+1,b);
		solve(e3,f+1,b);
	}
	else if(v==k){
		m=1;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			for(int s=1;s<=ans;s++){
				if((j>=ial[s])&&(j<=jal[s]))
					m=2;
				else if((j+i-1>=ial[s])&&(j+i-1<=jal[s]))
					m=2;
			}
			if(m==2){
				m=0;
				continue;
			}
			solve(j,j+1,j+i-1);
			if(m){
				ans++;
				//cout<<j<<" "<<j+i-1<<endl;
				ial[ans]=j;
				jal[ans]=j+i-1;
			}
			m=0;
		}
	}
	cout<<ans;
	return 0;
} 
