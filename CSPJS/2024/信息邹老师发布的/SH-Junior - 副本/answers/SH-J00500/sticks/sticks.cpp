#include<bits/stdc++.h>//1
using namespace std;//2
int T;
long long ans[1000];//16 digits/each
int compass[8]={-1,-1,1,7,4,2,6,8};
int main(){//3{
    freopen("sticks.in","r",stdin);//4
    freopen("sticks.out","w",stdout);//5
    cin>>T;
    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        vector<int> num;
        int wei=0;
        while(n>0){
            int nn=0;
            if(n==11){
                num.push_back(0);
                nn=5;
            }
            else if(n==8 || n==9){
                num.push_back(compass[n-2]);
                nn=2;
            }
            else if(n==10){
                num.push_back(2);
                nn=5;
            }
            else if(n>11){
                num.push_back(8);
                nn=n-7;
            }
            else if(n<8){
                num.push_back(compass[n]);
                nn=0;
            }
            n=nn;
            wei++;
        }
        for(int j=0;j<wei;j++){
            ans[j/16]+=num[j]*pow(10,j%16);
        }
        for(int j=(wei-1)/16;j>-1;j--){
            cout<<ans[j];
            ans[j]=0;
        }
        cout<<endl;
    }
    return 0;//6
}//3
