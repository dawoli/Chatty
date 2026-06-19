#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX=1e5+2;
struct club{
    int one,two,three;
} a[MAX];
bool bmp1(club a,club b) {return a.one>b.one;}
bool bmp2(club a,club b) {return a.two>b.two;}
bool bmp3(club a,club b) {return a.three>b.three;}
// bool bmp4(club a,club b) {return a.index<b.index;}
// int num=0,bsn=0;
int best[4][MAX],num11,num22,num33,n,num;
int solve(int n1,int n2,int hasnum);
int main()
{
    //ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        // a[0].one=0,a[0].two=0,a[0].three=0,a[0].index=0;
        for(int j=1;j<=n;j++){
            cin>>a[j].one>>a[j].two>>a[j].three;
        }
        num=0,num11=0,num22=0,num33=0;
        // sort(a+1,a+n+1,bmp3);
        // int n3best=a[1].three;
        // for(int j=1;j<=n;j++) best[3][j]=a[j].index;
        // sort(a+1,a+n+1,bmp2);
        // int n2best=a[1].two;
        // for(int j=1;j<=n;j++) best[2][j]=a[j].index;
        // sort(a+1,a+n+1,bmp1);
        // int n1best=a[1].one;
        // for(int j=1;j<=n;j++) best[1][j]=a[j].index;
        // cout<<max(solve(1,1,0),max(solve(1,2,0),solve(1,3,0)))<<"\n";
        // num=0,num11=0,num22=0,num33=0;
        // cout<<solve(1,1,0)<<" "<<solve(1,2,0)<<" "<<solve(1,3,0)<<"\n";


        // sort(a+1,a+n+1,bmp4);
        ll num1=0,n1=0,n2=0,n3=0,num2=0,num3=0;
        // if(n1best<n2best&&n1best<n3best){
        //     if(n2best>n3best) sort(a+1,a+n+1,bmp2);
        //     else sort(a+1,a+n+1,bmp3);
        // }
        sort(a+1,a+n+1,bmp1);
        for(int j=1;j<=n;j++){
            if(a[j].one>=a[j].two&&a[j].one>=a[j].three&&n1<n/2){
                n1++,num1+=a[j].one;
                // cout<<"1: "<<j<<" "<<a[j].one<<" "<<a[j].two<<" "<<a[j].three<<"\n";
                a[j].two=0,a[j].three=0;
            }
        }
        sort(a+1,a+n+1,bmp2);
        for(int j=1;j<=n;j++){
            if(a[j].two>=a[j].one&&a[j].two>=a[j].three&&n2<n/2){
                n2++,num1+=a[j].two;
                // cout<<"2: "<<j<<" "<<a[j].one<<" "<<a[j].two<<" "<<a[j].three<<"\n";
                a[j].one=0,a[j].three=0;
            }
        }
        sort(a+1,a+n+1,bmp3);
        for(int j=1;j<=n;j++){
            if(a[j].three>=a[j].one&&a[j].three>=a[j].two&&n3<n/2){
                n3++,num1+=a[j].three;
                // cout<<"3: "<<j<<" "<<a[j].one<<" "<<a[j].two<<" "<<a[j].three<<"\n";
                a[j].one=0,a[j].two=0;
            }
        }

        // for(int j=1;j<=n;j++){
        //     if(a[j].one>=a[j].two&&a[j].one>=a[j].three&&n1<n/2){
        //         n1++,num+=a[j].one;
        //         cout<<"1: "<<j<<" "<<a[j].one<<" "<<a[j].two<<" "<<a[j].three<<"\n";
        //         a[j].two=0,a[j].three=0;
        //     }
        //     else if(a[j].two>=a[j].one&&a[j].two>=a[j].three&&n2<n/2){
        //         n2++,num+=a[j].two;
        //         cout<<"2: "<<j<<" "<<a[j].one<<" "<<a[j].two<<" "<<a[j].three<<"\n";
        //         a[j].one=0,a[j].three=0;
        //     }
        //     else if(a[j].three>=a[j].one&&a[j].three>=a[j].two&&n3<n/2){
        //         n3++,num+=a[j].three;
        //         cout<<"3: "<<j<<" "<<a[j].one<<" "<<a[j].two<<" "<<a[j].three<<"\n";
        //         a[j].one=0,a[j].two=0;
        //     }
        //     else {
        //         if(a[j].one>a[j].two&&n1+1<=n/2){
        //             num+=a[j].one;
        //             cout<<"1: "<<j<<" "<<a[j].one<<" "<<a[j].two<<" "<<a[j].three<<"\n";
        //             a[j].two=0,a[j].three=0;
        //         }
        //         else{
        //             num+=a[j].two;
        //             cout<<"2: "<<j<<" "<<a[j].one<<" "<<a[j].two<<" "<<a[j].three<<"\n";
        //             a[j].one=0,a[j].three=0;
        //         }
        //     }
        // }
        cout<<num1<<"\n";
    }
    return 0;
}
// int solve(int n1,int n2,int hasnum){
//     if(n1-1==n) return 0;
//     if(n2==1){
//         if(num11==n/2) return 0;
//         hasnum+=a[n1].one;
//         num11++;
//         if(n1==n) return hasnum;
//         return max(hasnum+solve(n1+1,1,hasnum),max(hasnum+solve(n1+1,2,hasnum),hasnum+solve(n1+1,3,hasnum)));
//     }
//     if(n2==2){
//         if(num22==n/2) return 0;
//         hasnum+=a[n1].two;
//         num22++;
//         if(n1==n) return hasnum;
//         return max(hasnum+solve(n1+1,1,hasnum),max(hasnum+solve(n1+1,2,hasnum),hasnum+solve(n1+1,3,hasnum)));
//     }
//     if(n2==3){
//         if(num33==n/2) return 0;
//         hasnum+=a[n1].three;
//         num33++;
//         if(n1==n) return hasnum;
//         return max(hasnum+solve(n1+1,1,hasnum),max(hasnum+solve(n1+1,2,hasnum),hasnum+solve(n1+1,3,hasnum)));
//     }
// }