#include<bits/stdc++.h>//1
using namespace std;//2
int T;
int exmap[1010][1010];
char geog[1010][1010];
int main(){//3
    freopen("explore.in","r",stdin);//4
    freopen("explore.out","w",stdout);//5
    cin>>T;
    for(int i=1;i<=T;i++){
        int n,m,k,ax,ay,d;
        int ans=0;
        cin>>n>>m>>k;
        cin>>ax>>ay>>d;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                cin>>geog[j][l];
            }
        }
        exmap[ax][ay]=1;
        ans++;
        for(int tim=1;tim<=k;tim++){
            int nx,ny;
            nx=ax;
            ny=ay;
            if(d==0) ny++;
            else if(d==1) nx++;
            else if(d==2) ny--;
            else if(d==3) nx--;
            //cout<<"nx="<<nx<<' '<<"ny="<<ny<<endl;//yyy
            int fnx,fny;
            if(((nx>0 && nx<n+1) && (ny>0 && ny<m+1)) && (geog[nx][ny]=='.')){
                fnx=nx;
                fny=ny;
            }
            else{
                fnx=ax;
                fny=ay;
                int nd=(d+1)%4;
                d=nd;
                //cout<<"d="<<d<<endl;//yyy
            }
            //cout<<"fnx="<<fnx<<' '<<"fny="<<fny<<endl;//yyy
            if(exmap[fnx][fny]==0) ans++;
            exmap[fnx][fny]=1;
            ax=fnx;
            ay=fny;
            //cout<<"ans="<<ans<<endl;//yyy
        }
        cout<<ans<<endl;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                exmap[j][l]=0;
            }
        }
    }
    return 0;//6
}//3
