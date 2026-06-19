#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int ton[100001]={};
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        ton[tmp]++;
    }
    int ns=-1;
    for(int i=1;i<=100000;i++){
        if(ton[i]!=0){
            for(int j=max(i+1,ns);j<=100000;j++){
                if(ton[j]>=ton[i]){
                    n-=ton[i];
                    ton[i]=0;
                    i=j-1;
                    break;
                }
                else if(ton[j]!=0){
                    ton[i]-=ton[j];
                    ns=max(ns,j+1);
                    n-=ton[j];
                }
            }
        }
    }
    cout<<n<<endl;
    fclose(stdin);
    fclose(stdout);
}
