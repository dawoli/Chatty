#include <bits/stdc++.h>
using namespace std;

int n,m,k,x,y,d;
int ans;
bool A[1005][1005]={0};
bool book[1005][1005]={0};
ifstream fin("explore.in");
ofstream fout("explorer.out");

int main(){
    int T;
    fin >> T;

    while (T--){
        for (int i=1;i<=1005;i++){
        	for (int j=0;j<1005;j++){
            	book[i][j]=0;
        	}
    	}
        //cout << "compute:" << " " << T << endl;
        fin >> n >> m >> k;
        fin >> x >> y >> d;
        
        for (int i=1;i<=n;i++){
            string s;
            fin >> s;
            for (int j=0;j<m;j++){
                if (s[j]=='.') A[i][j] = 0;
                else if (s[j]=='x') A[i][j] = 1;
            }
        } 
        //cout << "map is:\n";
        //for (int i=1;i<=n;i++){
            //for (int j=0;j<m;j++){
                //cout << A[i][j];
            //}
            //cout <<"\n";
        //} 
        //cout << endl;

        book[x][y]=1;
        cout << "the start time x=" << x <<",y=" <<y<<",k="<<k<<" \n";
        while (k--){
            //cout << "Now k=" << k << "    ";
            int x_=0,y_=0;
            while (1){
                if (d==0) {x_=x;y_=y+1;}
                else if (d==1) {x_=x+1;y_=y;}
                else if (d==2) {x_=x;y_=y-1;}
                else if (d==3) {x_=x-1;y_=y;}
                //cout << "Now x_=" << x_ << " "<< "Now y_=" << y_<< " "<< "Now d_=" << d<< endl;
                //cout << "Now x=" << x << " "<< "Now y=" << y<< " "<< endl << endl;
                
                if (A[x_][y_-1]==0 and x_>=1 and x_ <=n and y_>=1 and y_<=m){
                    x=x_;
                    y=y_;
                    //cout << "Walk to x,y=(" << (int)x <<',' << (int)y <<")"<<endl;
                    book[x][y]=1;
                    break;
                }
                else{
                    //cout << "turn from "<<d <<" to "<<(d+1)%4<<" because the next step is ("<<x_<<","<<y_<<")\n";
                    d=(d+1)%4;
                    break;
                }
            }
            
        }

        
        ans=0;
        for (int i=1;i<=n;i++){
            for (int j=0;j<m;j++){
                if (book[i][j]==1){
                    //cout << "i:"<<i<<" "<<"j:"<<j<<endl;
                    ans = ans+1;
                }
            }
        }
        //cout << "\n\n\n";
        fout << ans << endl;
    }
    return 0;
}
