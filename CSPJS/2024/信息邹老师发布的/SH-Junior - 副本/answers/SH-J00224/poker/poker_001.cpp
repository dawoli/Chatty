#include<iostream>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,t=0;
    char s[5][15]={},a[3];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        char x=a[0],y=a[1];
        int x1,y1;
        if(x=='D'){
            x1=0;
        }
        if(x=='C'){
            x1=1;
        }
        if(x=='H'){
            x1=2;
        }
        if(x=='S'){
            x1=3;
        }
        y1=y-49;
        if(y1==16){
        	y1=0;
		} 
        if(y1==16+9){
            y1=9;
        }
        if(y1==16+10){
            y1=10;
        }
        if(y1==16+16){
            y1=11;
        }
        if(y1==16+19){
            y1=12;
        }
        s[x1][y1]=1;
    }
    for(int i=0;i<4;i++){
    	for(int j=0;j<13;j++){
    		if(s[i][j]==0){
    			t++;
			}
		}
    }
    cout<<t;
    return 0;
}
