#include<iostream>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    int t,n,m,k,x,y,d;
    cin>>t;
    for(int i=0;i<t;i++){
        char a[1010][1010]={};
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                cin>>a[j][l];
            }
        }
        for(int j=0;j<k;j++){
            int x1,y1;
            a[x][y]='1';
            if(d==0){
                x1=x;
                y1=y+1;
            }
            if(d==1){
                x1=x+1;
                y1=y;
            }
            if(d==2){
                x1=x;
                y1=y-1;
            }
            if(d==3){
                x1=x-1;
                y1=y;
            }
            if(x1>n||y1>m||a[x1][y1]=='x'||x1<=0||y1<=0){
                d=(d+1)%4;
            }
            else if(!(x1>n||y1>m||a[x1][y1]=='x'||x1<=0||y1<=0)){
                x=x1;
                y=y1;
            }
            a[x][y]='1';
        }
        int s=0;
        for(int j=0;j<=n;j++){
            for(int l=0;l<=m;l++){
                if(a[j][l]=='1'){
                    s++;
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
