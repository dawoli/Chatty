#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int p=0,sum=0,mm;
        int a[10]={0,0,0,0,0,0,0,0,0,0};
        for(int i=1;i<=8;i++){
            string s;
            cin>>s;
            if(s[0]=='m')a[1]++;
            if(s[0]=='m')p++;
        }
        for(int i=9;i<=16;i++){
            string s;
            cin>>s;
            if(s[0]=='m')a[2]++;
            if(s[0]=='m')p++;
        }
        for(int i=17;i<=24;i++){
            string s;
            cin>>s;
            if(s[0]=='m')a[3]++;
            if(s[0]=='m')p++;
        }
        for(int i=25;i<=32;i++){
            string s;
            cin>>s;
            if(s[0]=='m')a[4]++;
            if(s[0]=='m')p++;
        }
        for(int i=33;i<=40;i++){
            string s;
            cin>>s;
            if(s[0]=='m')a[5]++;
            if(s[0]=='m')p++;
        }
        //cout<<p<<endl;
        //for(int i=1;i<6;i++){
        //    cout<<a[i]<<" ";
        //}
        //cout<<endl;
        int n,m;
        cin>>n>>m;
        mm=7-m;
        for(int i=m;i<m+mm+1;i++){
            sum+=a[i];
        }
        n=n-mm-1;
        int x,y;
        x=n/7;
        y=n%7;
        sum+=x*p;
        for(int i=1;i<y+1;i++){
            sum+=a[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
