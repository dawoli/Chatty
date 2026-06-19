#include <iostream>
using namespace std;
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    int T;
    cin>>T;
    int biao1[6]={8,0,6,2,7,1};
    int biao2[6]={7,6,6,5,3,2};
    for (int i=0;i<T;i++) {
        int n;
        cin>>n;
        int a=0;
        if (n<2) {
            cout<<-1<<endl;
        } else {
            while (n>0) {
                if (n<=7 && n>1 && n!=4) {
                    if (a==0) {
                        for (int i=0;i<6;i++) {
                            if (n==biao2[i] && biao1[i]!=0) {
                                cout<<biao1[i]<<endl;
                                n=0;
                                break;
                            }
                        }
                    } else {
                        for (int i=0;i<6;i++) {
                            if (n==biao2[i]) {
                                cout<<biao1[i]<<endl;
                                n=0;
                                break;
                            }
                        }
                    }
                } else if (n%7==0) {
                    while (n>0){
                        cout<<8;
                        n-=7;
                    }
                    cout<<endl;
                    break;
                } else if (n%7==1&&n>1) {
                    cout<<10;
                    n-=8;
                    a=1;
                } else {
                    cout<<-1<<endl;
                    n=0;
                    break;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}