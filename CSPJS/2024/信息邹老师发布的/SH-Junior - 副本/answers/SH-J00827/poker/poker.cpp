#include <bits/stdc++.h>
using namespace std;
struct cards{
    string Name;
    int Num;
};
cards poker[52];
string n[1000000];
int cardnumber,number;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>cardnumber;
    for(int i=0;i<52;i++){
        poker[i].Name="0";
        poker[i].Num=0;
    }
    for(int i=0;i<cardnumber;i++){
        cin>>n[i];
    }
    for(int i=0;i<cardnumber;i++){
        bool flag=0;
        for(int j=0;j<52;j++){
            if(n[i]==poker[j].Name){
                poker[j].Num++;
                flag=1;
                break;
            }
        }
        if(flag==0){
            for(int j=0;j<52;j++){
                if(poker[j].Name=="0"){
                    poker[j].Name=n[i];
                    poker[j].Num++;
                    break;
                }
            }
        }
    }
    for(int i=0;i<52;i++){
        if(poker[i].Name=="0"||poker[i].Num==0){
            number++;
        }
    }
    cout<<number;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
