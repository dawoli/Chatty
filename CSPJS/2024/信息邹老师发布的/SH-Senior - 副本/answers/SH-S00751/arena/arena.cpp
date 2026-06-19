#include<bits/stdc++.h>
using namespace std;
int T,n,m,a1[100010],c[100010],d[100010][50];
string s;
struct Node{
	int id,p;
}a[5010];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a1[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	int K=0;
	for(int i=1;i<=n;i++){
		if(pow(2,K)<=n) K++;
	}
	for(int i=1;i<=K;i++){
		getline(cin,s);
		for(int j=0;j<s.size();j++){
			d[i][j+1]=s[j]-'0';
		}
	}
	cin>>T;
	while(T--){
		int x[4];
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=m;i++){
			for(int r=1;r<=n;r++){
				a[r].p=a1[r] | x[r%4];
				a[r].id=r;
			}  
			int R=0,k,N=n;
			if(pow(2,R)<c[i]) R++;
			int q=R;
			for(R;R>=1;R--){
				k=1;
				while(k*2<=c[i]){
					if(d[R][k]){
						if(a[k*2].p>=q-R+1){
							for(int l=k*2;l<=N;l++){
								a[l-1].p=a[l].p;
								a[l-1].id=a[l].id;
							}
						}else{
							for(int l=k*2;l<=N;l++){
								a[l].p=a[l+1].p;
								a[l].id=a[l+1].id;
							}
						}
					}else{
						if(a[k*2-1].p<q-R+1){
							for(int l=k*2;l<=N;l++){
								a[l-1].p=a[l].p;
								a[l-1].id=a[l].id;
							}
						}else{
							for(int l=k*2;l<=N;l++){
								a[l].p=a[l+1].p;
								a[l].id=a[l+1].id;
							}
						}
					}
					k++;N--;
				}
			}
		}
		cout<<a[1].id<<endl;
	}
	return 0; 
} 
/*
5 5
0 0 0 0 0
5 4 1 2 3
1001
10
1
4
2 1 0 0
1 2 1 0
0 2 3 1
2 2 0 1
*/
