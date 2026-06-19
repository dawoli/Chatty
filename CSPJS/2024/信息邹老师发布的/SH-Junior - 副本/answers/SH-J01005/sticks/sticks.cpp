#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<'\n';
        }else{
            long long cnt=0,i=0;
            while(1){
            	i++;
                cnt=0;
                long long k=i;
                while(k>0){
                    int te=k%10;
                    k/=10;
                    if(te==8){
                        cnt+=7;
                    }
                    if(te==0||te==9||te==6){
                        cnt+=6;
                    }
                    if(te==2||te==3||te==5){
                        cnt+=5;
                    }
                    if(te==4){
                        cnt+=4;
                    }
                    if(te==7){
                        cnt+=3;
                    }
                    if(te==1){
                        cnt+=2;
                    }
                }
                if(cnt==n){
                	break;
				}
				
            }
            cout<<i<<'\n';
        }
    }
    return 0;
}
/*
5
1
2
3
6
18
*/
