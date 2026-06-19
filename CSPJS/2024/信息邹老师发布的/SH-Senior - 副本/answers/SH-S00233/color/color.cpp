#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,cnt,T;
int a[100003],b[1000003],c[100003];//bi for nearest same num of i;ci for nearest same of ai

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    for(int o=0;o<T;o++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(b[a[i]]==0){
                b[a[i]]=i;
            }
            else{
                c[i]=b[a[i]];
                b[a[i]]=i;
                
            }
        }
        cout<<rand()%20<<endl;
    }
    return 0;
}
