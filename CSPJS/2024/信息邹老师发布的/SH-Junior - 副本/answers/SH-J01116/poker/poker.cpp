#include<bits/stdc++.h>
using namespace std;
bool a[4][20];//d[20][2],c[20][2],h[20][2],S[20][2];
int n,ans;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char xxx,yyy;
		cin>>xxx>>yyy;
		int z=0;
		if(xxx=='D'){
            z=0;
		}else if(xxx=='C'){
			z=1;
		}else if(xxx=='H'){
			z=2;
		}else{
			z=3;
		}
		if(yyy>='2'&&yyy<='9'){
			a[z][yyy-'0']=1;
		}else if(yyy=='A'){
			a[z][1]=1;
		}else if(yyy=='T'){
			a[z][10]=1;
		}else if(yyy=='J'){
			a[z][11]=1;
		}else if(yyy=='Q'){
			a[z][12]=1;
		}else if(yyy=='K'){
			a[z][13]=1;
		}
	}
	for(int i=0;i<4;i++){
		for(int j=1;j<=13;j++){
			if(a[i][j]==0){
				ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
