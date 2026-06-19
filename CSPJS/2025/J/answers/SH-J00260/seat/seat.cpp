#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int score[n*m],scorei,NUM;
    for(int i=0;i<(n*m);i++){
        cin>>score[i];
    }
    scorei=score[0];
    for(int i=0;i<(n*m);i++){
        for(int j=0;j<i;j++){
            if(score[j]<score[j+1]){
                swap(score[j],score[j+1]);
            }
        }
    }
    for(int i=0;i<(n*m);i++){
        if(score[i]==scorei){
            NUM=i;
        }
    }
    int c=(NUM/m)+1;
    int r;
    if(c%2==0){
        r=c*m-NUM;
    }
    else{
        r=(NUM%m)+1;
    }
    cout<<c<<' '<<r;
    return 0;
}

