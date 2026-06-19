#include<bits/stdc++.h>
using namespace std;
int a[1005][2005];
int l[1005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int tmp;
	cin>>tmp;
	while(tmp--){
		int n,num,q;
		cin>>n>>num>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			int flag=0;
			for(int k=1;k<=n;k++){
				for(int j=1;j<=l[i];j++){
					if(a[k][j]==1){
						for(int qwe=j+1;qwe<num+j;qwe++){
							if(a[k][qwe]==y){
								printf("1\n");
								flag=1;
								break;
							}
						}
						if(flag==1){
							break;
						}
					}
				}
				if(flag==1){
					break;
				}
			}
			if(flag==0){
				printf("0\n");
			}
		}
	}
	return 0;
} 
