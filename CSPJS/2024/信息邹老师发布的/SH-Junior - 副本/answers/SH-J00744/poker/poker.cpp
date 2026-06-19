#include <bits/stdc++.h>
using namespace std;

int A[53]={0};
int ans = 0;
ifstream fin("poker.in");
ofstream fout("poker.out");

void f(string n){
    if (n=="DA") A[0]++;
    else if (n=="D2") A[1]++;
    else if (n=="D3") A[2]++;
    else if (n=="D4") A[3]++;
    else if (n=="D5") A[4]++;
    else if (n=="D6") A[5]++;
    else if (n=="D7") A[6]++;
    else if (n=="D8") A[7]++;
    else if (n=="D9") A[8]++;
    else if (n=="DT") A[9]++;
    else if (n=="DJ") A[10]++;
    else if (n=="DQ") A[11]++;
    else if (n=="DK") A[12]++;

    else if (n=="CA") A[13]++;
    else if (n=="C2") A[14]++;
    else if (n=="C3") A[15]++;
    else if (n=="C4") A[16]++;
    else if (n=="C5") A[17]++;
    else if (n=="C6") A[18]++;
    else if (n=="C7") A[19]++;
    else if (n=="C8") A[20]++;
    else if (n=="C9") A[21]++;
    else if (n=="CT") A[22]++;
    else if (n=="CJ") A[23]++;
    else if (n=="CQ") A[24]++;
    else if (n=="CK") A[25]++;

    else if (n=="HA") A[26]++;
    else if (n=="H2") A[27]++;
    else if (n=="H3") A[28]++;
    else if (n=="H4") A[29]++;
    else if (n=="H5") A[30]++;
    else if (n=="H6") A[31]++;
    else if (n=="H7") A[32]++;
    else if (n=="H8") A[33]++;
    else if (n=="H9") A[34]++;
    else if (n=="HT") A[35]++;
    else if (n=="HJ") A[36]++;
    else if (n=="HQ") A[37]++;
    else if (n=="HK") A[38]++;

    else if (n=="SA") A[39]++;
    else if (n=="S2") A[40]++;
    else if (n=="S3") A[41]++;
    else if (n=="S4") A[42]++;
    else if (n=="S5") A[43]++;
    else if (n=="S6") A[44]++;
    else if (n=="S7") A[45]++;
    else if (n=="S8") A[46]++;
    else if (n=="S9") A[47]++;
    else if (n=="ST") A[48]++;
    else if (n=="SJ") A[49]++;
    else if (n=="SQ") A[50]++;
    else if (n=="SK") A[51]++;
}
int main(){
    int n;
    string s;
    fin >> n;
    //DCHS  A 2 3 4 5 6 7 8 9 T J Q K
    while(n--){
        fin >> s;
        f(s);
    }
    for(int i=0;i<=51;i++){
        if (A[i]==0){
            ans++;
        }
    }
    fout << ans;
    return 0;
}
