#include <iostream>
using namespace std;

int n, pre;// int monsters[100010];
int bucketsort[100010];
int re;
//bool attacked[100010];

int main() {


    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;

        bucketsort[t]++;
    }

    // 2->1, 3->2, 4->3, ...
    bool first=true;
    for(int i=0;i<100010;i++){
        if(bucketsort[i]!=0){
            //printf("%d %d's attack remaining %d: ", bucketsort[i], i, re);
            if(first==true){
               // pre = i;
                re = bucketsort[i];
                first=false;
            }else{
                if(bucketsort[i]>re){
                    //printf("all gone\n");
                    n -= re;
                    re = bucketsort[i];
                }else{
                    //printf("%d remain\n", re-bucketsort[i]);
                    n -= bucketsort[i];
                    //re -= bucketsort[i];
                }

                //pre = i;
            }
        }
        if(n==1)break;
    }

    cout<<n<<endl;


    return 0;
}
