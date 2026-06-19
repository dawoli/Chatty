#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vCard;
vector<bool> vbAttack,vbAlive;
 int _num=0;
/*void print_card()
{
    for(int i=0;i<vbAttack.size();i++)
    {
        cout<<vbAttack[i]<<" ";
    }
}*/
bool isAttackAll()
{
    for(int i=0;i<vbAttack.size();i++)
    {
        if(vbAttack[i])
        {
            return 0;
        }
    }
    return 1;
}
struct label
{
    int num=0;
    int strong=0;
};
void solve()
{
    vector<label> vSort;
    vector<label> vAttackSort;
    label nTemp;
    struct label lb;
    while(!isAttackAll())
    //for(int i=0;i<2;i++)
    {
        for(int i=0;i<vCard.size();i++)
        {
            if(vbAlive[i])
            {
                lb.num=i;
                lb.strong=vCard[i];
                vSort.push_back(lb);
            }
        }
        sort(vSort.begin(),vSort.end(),[](label &a,label &b){return a.strong<b.strong;});
        nTemp=vSort[0];
        for(int i=0;i<vCard.size();i++)
        {
            if(vbAlive[i]&&vbAttack[i]&&vCard[i]>nTemp.strong)
            {
                lb.num=i;
                lb.strong=vCard[i];
                vAttackSort.push_back(lb);
            }
        }
        if(!vAttackSort.empty())
        {
            sort(vAttackSort.begin(),vAttackSort.end(),[](label &a,label &b){return a.strong<b.strong;});
            vbAlive[nTemp.num]=0;
            vbAttack[nTemp.num]=0;
            vbAttack[vAttackSort[0].num]=0;
        }
        else{
            goto EXIT;
        }

        /*for(int i=0;i<vSort.size();i++)
        {
             cout<<vSort[i].strong<<" ";
        }
        cout<<endl;
        for(int i=0;i<vAttackSort.size();i++)
        {
             cout<<vAttackSort[i].strong<<" :";
             cout<<vAttackSort[i].num<<" ";
        }*/
        vSort.clear();
        vAttackSort.clear();
        /*cout<<endl;
        print_card();
        cout<<endl;*/
    }

   EXIT: int j=0;
    for(int i=0;i<vCard.size();i++)
    {
        if(vbAlive[i])
        {
            j++;
        }
        //cout<<vAttackSort[i].num<<" ";
    }
    cout<<j<<endl;
}
int main()
{

    int nInput=0;
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>_num;
    vbAttack.resize(_num,1);
    vbAlive.resize(_num,1);
    for(int i=0;i<_num;i++)
    {
        cin>>nInput;
        vCard.push_back(nInput);
    }
    solve();
    //print_card();

    fclose(stdin);
    fclose(stdout);

    return 0;
}
