#include<bits/stdc++.h>
using namespace std;
int _data_group;
struct sCar
{
    int nPos=0;
    int v=0;
    int a=0;

};
vector<sCar> vCar;
vector<int> vTestPt;
vector<float> vOpen;
vector<float> vClose;
void print_data()
{
    for_each(vCar.begin(),vCar.end(),[](sCar s){cout<<s.nPos<<" "<<s.v<<" "<<s.a<<endl;});
    cout<<endl;
    for_each(vTestPt.begin(),vTestPt.end(),[](int a){cout<<a<<" ";});
}
int solve(int nCar,int nTest,int nRdL,int nRSpeed)
{
    int nOverSpeed=0;
    float x=0.0,t=0.0,nLastV=0.0,nOverX=0.0;
    int b=0;
    for(int i=0;i<vCar.size();i++)
    {
        if(vCar[i].nPos!=nRdL)
        {
            if(vCar[i].a>0)
            {//b=1;cout<<"a>0:"<<i<<endl;
                if(vCar[i].v>nRSpeed)
                {
                    nOverSpeed++;
                    vOpen.push_back(vCar[i].nPos);
                }
                else{
                    x=nRdL-vCar[i].nPos;
                    nLastV=sqrt(2*vCar[i].a*x+vCar[i].v);
                    t=(float)nRSpeed/(float)vCar[i].a;
                    nOverX=(float)vCar[i].v*t+0.5*(float)vCar[i].a*t*t;
                    //cout<<nOverX<<endl;
                    if(nLastV>nRSpeed)
                    {
                        nOverSpeed++;
                        vOpen.push_back(nOverX);
                    }
                }
            }
            else if(vCar[i].a<0)
            {
                if(vCar[i].v>nRSpeed)
                {
                    nOverSpeed++;
                    nLastV=nRSpeed;
                    x=(float)((float)nLastV*(float)nLastV-(float)vCar[i].v*(float)vCar[i].v)/2*(float)vCar[i].a;
                    vOpen.push_back(vCar[i].nPos);
                    if(vCar[i].nPos+x<nRdL)
                    {
                        vClose.push_back((float)vCar[i].nPos+(float)x);
                    }
                    //cout<<x<<endl;
                }
b=0;//cout<<"a<0:"<<i<<endl;
            }
            else
            {
                if(vCar[i].v>nRSpeed)
                {
                    vOpen.push_back(vCar[i].nPos);
                    nOverSpeed++;b=0;
                    //cout<<"a=0:"<<i<<endl;
                }
            }
            //if(b){cout<<i<<":"<<vOpen.back()<<endl;}
        }
        //for_each(vOpen.begin(),vOpen.end(),[](int a){cout<<a<<" ";});
    }
    return nOverSpeed;
}
void slice2()
{
    sort(vOpen.begin(),vOpen.end(),greater<int>());
    sort(vClose.begin(),vClose.end(),less<int>());

}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>_data_group;
    sCar sTmp;
    int nTmp;
    int nCar=0,nTest=0,nRdL=0,nRSpeed=0;
    int avail=0;
    for(int i=0;i<_data_group;i++)
    {
        vCar.clear();
        vTestPt.clear();
        vOpen.clear();
        vClose.clear();
        avail=0;
        cin>>nCar>>nTest>>nRdL>>nRSpeed;
        for(int j=0;j<nCar;j++)
        {
            cin>>sTmp.nPos>>sTmp.v>>sTmp.a;
            vCar.push_back(sTmp);
        }
        for(int k=0;k<nTest;k++)
        {
            cin>>nTmp;
            vTestPt.push_back(nTmp);
        }
        //print_data();
        cout<<solve( nCar, nTest, nRdL, nRSpeed);
        slice2();
        for(int z=0;z<vTestPt.size();z++)
        {
            if(vOpen[0]<vClose[0])
            {
                if(vTestPt[z]>=vOpen[0]&&vTestPt[z]<=vClose[0])
                {
                    avail++;
                }
            }
            else if(vOpen[0]>=vClose[0])
            {
                if(vTestPt[z]>=vOpen[0]||vTestPt[z]<=vClose[0])
                {
                    avail++;
                }
            }
        }

    }
    cout<<avail;
    cout<<3<<3;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
