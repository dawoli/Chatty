#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    int n,m,L,V;
    for(int i=0;i<t;i++){
        cin>>n>>m>>L>>V;
        int car[n][3],car2[3];
        int detector[m],count=0;
        for(int j=0;j<n;j++){
            cin>>car[j][0]>>car[j][1]>>car[j][2];
            if(car[j][1]>V){
                count++;
            }
        }
        for(int j=0;j<m;j++){
            cin>>detector[j];
        }
        cout<<count<<' '<<m-1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
