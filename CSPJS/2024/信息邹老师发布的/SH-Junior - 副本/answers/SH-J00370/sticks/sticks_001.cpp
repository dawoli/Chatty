#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t;
int main(){
    freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
        ll n;
        cin>>n;
        switch(n) {
            case 0:{
                cout<<-1<<endl;
                break;
            }
            case 1:{
                cout<<-1<<endl;
                break;
            }
            case 2:{
                cout<<1<<endl;
                break;
            }
            case 3:{
                cout<<7<<endl;
                break;
            }
            case 4:{
                cout<<4<<endl;
                break;
            }
            case 5:{
                cout<<2<<endl;
                break;
            }
            case 6:{
                cout<<6<<endl;
                break;
            }
            case 7:{
                cout<<8<<endl;
                break;
            }
            default: {
                ll q=n%7;
                if(q==1) {
                    cout<<10;
                }
                if(q==2) {
                    cout<<18;
                }
                if(q==3) {
                    cout<<22;
                }
                if(q==4) {
                    cout<<20;
                }
                if(q==5) {
                    cout<<28;
                }
                if(q==6) {
                    cout<<68;
                }
                if(q==0) {
                    cout<<88;
                }
                for(int i=1;i<n/8;i++) cout<<8;
                cout<<endl;
            }
        }
	}
	return 0;
}
