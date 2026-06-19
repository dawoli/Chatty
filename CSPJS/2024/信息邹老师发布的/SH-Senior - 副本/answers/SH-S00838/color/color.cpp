#include<bits/stdc++.h>
#define ll long long
#define N 20009
using namespace std;
int T,n;
int A[N];

inline bool query(ll con,int x){
	if((con>>x)&1) return true;
	return false;
}

void solveBF(){
	int ans=0;
	for(ll con=0;con<=(1<<n)-1;con++){
		int res=0;
		int lst0=-1,lst1=-1;
		for(int i=1;i<=n;i++){
			if(query(con,i-1)){
				if(lst1!=-1){
					if(A[i]==A[lst1])
						res+=A[i];
				}
				lst1=i;
			}
			else{
				if(lst0!=-1){
					if(A[i]==A[lst0])
						res+=A[i];
				}
				lst0=i;
			}
		}
		ans=max(ans,res);
	}
	cout<<ans<<endl;
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int a=1;a<=T;a++){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>A[i];
		if(n<=15) solveBF();
	}
	return 0;
} 
