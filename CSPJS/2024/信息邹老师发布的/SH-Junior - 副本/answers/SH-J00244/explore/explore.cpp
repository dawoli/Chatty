#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long int ans=1;
        long int h,l,t;
        cin>>h>>l>>t;
        long int posx,posy,face;
        cin>>posx>>posy>>face;
        int ji[h+1][l+1];
        //cout<<h<<' '<<l<<' '<<t<<' '<<posx<<' '<<posy<<' '<<face << endl;
        for(int j=0;j<=h;j++)
        {
            for(int k=0;k<=l;k++)
            {
                ji[j][k]=0;
            }
        }
        string m[h+1];
        for(int j=1;j<=h;j++)
        {
            string temp="";
            cin>>temp;
            m[j]=" ";
            m[j]=m[j]+temp;
        }
        ji[posx][posy]=1;
        for(int j=1;j<=h;j++)
        {
        	//cout<<m[j]<<endl; 
		}
        for(int j=1;j<=t;j++)
        {
        	//cout<<j<<endl;
            int tpx,tpy;
            if(face==0)
            {
                tpx=posx;tpy=posy+1;
            }
            if(face==1)
            {
                tpx=posx+1;tpy=posy;
            }
            if(face==2)
            {
                tpx=posx;tpy=posy-1;
            }
            if(face==3)
            {
                tpx=posx-1;tpy=posy;
            }
            if(1<=tpx && tpx<=h &&1<=tpy &&tpy<=l && m[tpx][tpy]!='x')
            {
            	//cout<<tpx<<' '<<tpy<<' '<<face<<"yes"<<tpx<<' '<<tpy<<' '<<m[tpx][tpy]<<endl;
                if(ji[tpx][tpy]==0)
                {
                	//cout<<"lllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll"<<endl;
                    ans=ans+1;
                    ji[tpx][tpy]=1;
                }
                //cout<<ans<<endl;
                posx=tpx;posy=tpy;
            }
            else
            {
            	//cout<<tpx<<' '<<tpy<<' '<<face<<"no"<<endl;
                face++;
                face=face%4;
            }
        }cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
