#include <bits/stdc++.h>
using namespace std;

int n;
const int go[8] = {0,0,1,7,4,2,0,8};
const char need[10] = {'6','2','5','5','4','5','6','3','7','6'};
string x[100010];//x[y],y sticks min

bool cmp(string &x,string &y){
    if(x.length()!=y.length())
        return x.length() < y.length();
    return x < y;
}

void mem(){
    for(int i = 1;i <= 100000;i++)
        x[i] = "";
    return;
}

void OK(){
    for(int i = 2;i <= 7;i++){
        char add = need[go[i]];
        if(i <= n) x[i] += add;
        for(int j = 0;j <= n;j++){
            if(i+j > n) return;
            for(int k = 0;k < x[i].length();i++){
                string now = x[i].substr(0,k)+add+x[i].substr(k);
                if(now[0]!='0'&&cmp(now,x[i+j])) x[i+j] = now;
            }
        }
    }
    return;
}


namespace A{
    int MAIN(){
        for(int i = 7;i <= n;i+=7){
            printf("8");
        }
        printf("\n");
        return 0;
    }
}

namespace B{
    int MAIN(){
        //like 1888880
        n-=8;
        printf("1");

        for(int i = 7;i <= n;i+=7){
            printf("8");
        }

        printf("0\n");
        return 0;
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n%7 == 0){
            A::MAIN();
            continue;
        }else if(n%7 == 1){
            B::MAIN();
            continue;
        }else{
            OK();
            cout << x[n] << endl;
        }
        mem();
    }
    return 0;
}//40