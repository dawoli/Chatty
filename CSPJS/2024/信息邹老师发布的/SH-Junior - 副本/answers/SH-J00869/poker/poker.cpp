#include<bits/stdc++.h>
using namespace std;
bool a[4][13];
int ans=52;
void doing(char x,int y){
    int xx;
    if(x=='A'){
        xx=0;
    }
    else if(x=='T'){
        xx=9;
    }
    else if(x=='J'){
        xx=10;
    }
    else if(x=='Q'){
        xx=11;
    }
    else if(x=='K'){
        xx=12;
    }
    else{
        xx=x-'1';
    }
    a[y][xx]=true;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char x,y;
        cin>>x>>y;
        if(x=='D'){
            doing(y,0);
        }
        else if(x=='C'){
        	doing(y,1);
		}
		else if(x=='H'){
			doing(y,2);
		}
		else{
			doing(y,3);
		}
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(a[i][j]==true){
                ans--;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
