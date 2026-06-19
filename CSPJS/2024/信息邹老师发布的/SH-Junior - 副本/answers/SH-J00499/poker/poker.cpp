#include<bits/stdc++.h>
using namespace std;

int n,ans=0;
bool a[5][14];

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++){
        char c1,c2;
        c1=getchar();
        c2=getchar();
        int type;
        if(c1=='D')type=1;
        else if(c1=='C')type=2;
        else if(c1=='H')type=3;
        else type=4;
        if('2'<=c2&&c2<='9')a[type][c2-'0']=true;
        else if(c2=='A')a[type][1]=true;
        else if(c2=='T')a[type][10]=true;
        else if(c2=='J')a[type][11]=true;
        else if(c2=='Q')a[type][12]=true;
        else a[type][13]=true;
        getchar();
	}
	for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!a[i][j])ans++;
        }
	}
    printf("%d",ans);
    return 0;
}
