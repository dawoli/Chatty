#include<bits/stdc++.h>
using namespace std;
int a[100005][200005];
int b[100005][2];
int n,k,d=0,t;
//int f(int c,int l){
//	d++;
//	for(int i=1;i<=a[c][0];i++){
//		if(a[c][i]==l){
//			for(int j=1;j<=k;j++){
//				for(int q=1;q<=n;q++){
//					if(q!=c){
//						if(f(q,a[c][i+j])==1) return 1;
//						else if(d>b[t][0]) return 0;
//						else if(a[q][i+j]==b[t][1]) return 1;
//					}
//			    }
//			}
//		}
//	}
//	return 0;
//}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
    int T;
	cin>>T;
	for(int u=1;u<=T;u++){
		int q;
		cin>>n>>k>>q;
				for(int i=1;i<=n;i++){
			cin>>a[i][0];
			for(int r=1;r<=a[i][0];r++){
				cin>>a[i][r];
			}
		}
		for(t=1;t<=q;t++){
			cin>>b[t][0]>>b[t][1];
//			for(int j=1;j<=n;j++){
//				if(f(j,1)) cout<<'1';
//				break;
//			}
			if(b[t][0]%2==1) cout<<1;
			else cout<<0;
		}
	}
	return 0;
}
