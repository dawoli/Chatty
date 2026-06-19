#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct Node{
    double s,d,l1,l2;
}car[N];
int a[N],b[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,l,v;
        cin>>n>>m>>l>>v;
        int cnt=0;
        for(int i=0;i<n;i++){
            cin>>car[i].d>>car[i].l1>>car[i].l2;
            int v1=car[i].l1,t1=0;
            while(v1>v||v1<=0||car[i].s>l){
                v1+=car[i].l2;
                car[i].s=car[i].l1+1.0*0.5*car[i].l2;
                cout<<car[i].s<<'\n';
            }
            car[i].s+=car[i].d;
            if(v1<v){
            	car[i].s=-1;
            }
        }
        for(int i=1;i<=m;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            if(car[i].s>a[m-1]){
                cnt++;
            }
        }
        cout<<cnt<<' ';
        int cnt2=m;
        for(int i=0;i<n;i++){
            for(int j=1;j<=m;j++){
                if((car[i].s<a[j]||car[i].s>a[i-1])&&(b[j]&&b[j-1])){
                    cnt2--;
                    b[j]=1;
                    b[j-1]=1;
                    break;
                }
            }
        }
        cout<<cnt2<<'\n';
    }
    return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
*/
