#include<bits/stdc++.h>
using namespace std;
int n,k,q;
int l[100005];
int a[1005][2005];
int r[105],c[100005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k >> q;
		for(int i=1;i<=n;i++){
			cin >> l[i];
			if(l[i]==1){
				n--;
				i--;
				continue;
			} 
			for(int j=1;j<=l[i];j++){
				cin >> a[i][j];
			}
		}
		for(int i=1;i<=q;i++){
			cin >> r[i] >> c[i];
			if(r[i]==1){
				for(int j=1;j<=n;j++){
					bool flag1=false,flag2=false;
					int f1,f2=0;
					for(int s=1;s<=l[j];s++){
						if(a[j][s]==1){
							flag1=true;
							f1=j;
						}
						if(flag1&&a[j][s]==c[i]){
							flag2=true;
							f2=j;
							break;
						}
					}
					if(flag2){
						if(f2-f1+1<=k&&f2-f1+1>=2){
							cout << 1 << endl;
							break;
						}
						else{
							cout << 0 << endl;
							break;
						}
					}
					else{
						cout << 0 << endl;
						break;
					}
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
