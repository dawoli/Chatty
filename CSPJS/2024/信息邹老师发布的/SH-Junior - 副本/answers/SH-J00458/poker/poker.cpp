#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,temp;//D=1,C=2,H=3,S=4
    bool card[4][13]={0};
    cin>>n;
    char b,c;
    for(int i=0;i<n;i++)
        {
        cin>>b>>c;
        switch(b)
        {
            case 'D':
                switch(c){
                    case 'A':card[0][0]=1;break;
                    case 'T':card[0][9]=1;break;
                    case 'J':card[0][10]=1;break;
                    case 'Q':card[0][11]=1;break;
                    case 'K':card[0][12]=1;break;

                    default:
                        temp=c-'0'-1;
                        card[0][temp]=1;
                        break;
                }
                break;
                        
                        
            case 'C':
                switch(c){
                    case 'A':card[1][0]=1;break;
                    case 'T':card[1][9]=1;break;
                    case 'J':card[1][10]=1;break;
                    case 'Q':card[1][11]=1;break;
                    case 'K':card[1][12]=1;break;

                    default:
                        temp=c-'0'-1;
                        card[1][temp]=1;
                }
                break;
            case 'H':
                switch(c){
                    case 'A':card[2][0]=1;break;
                    case 'T':card[2][9]=1;break;
                    case 'J':card[2][10]=1;break;
                    case 'Q':card[2][11]=1;break;
                    case 'K':card[2][12]=1;break;

                    default:
                        temp=c-'0'-1;
                        card[2][temp]=1;
                 break;
                }
                        break;
            case 'S':
                switch(c){
                    case 'A':card[3][0]=1;break;
                    case 'T':card[3][9]=1;break;
                    case 'J':card[3][10]=1;break;
                    case 'Q':card[3][11]=1;break;
                    case 'K':card[3][12]=1;break;

                    default:
                        temp=c-'0'-1;
                        card[3][temp]=1;
                        break;
                }
                break;

        }
    }
    int sum=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(card[i][j])
            {
                sum++;
            }
        }
    }
    cout<<52-sum;
    return 0;
}
