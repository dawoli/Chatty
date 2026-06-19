#include<bits/stdc++.h>
using namespace std;
int n,m,t,row=1,col=1;
bool add=true;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int stu[n*m];
    for(int i=0;i<n*m;i++)
        cin>>stu[i];
    t=stu[0];
    sort(stu,stu+n*m);
    for(int j=n*m-1;j>=0;j--){
        if(stu[j]==t){
            cout<<col<<' '<<row;
            break;
        }
        if((row==n&&add)||(row==1&&!add)){
            col++;
            add=!add;
            if(stu[j]==t){
                cout<<col<<' '<<row;
                break;
            }
        }
        else{
            if(stu[j]==t){
            cout<<col<<' '<<row;
            break;
            }
            row+=add?1:-1;
        }
    }
    return 0;
}
