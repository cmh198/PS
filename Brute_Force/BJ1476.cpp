#include <iostream>

using namespace std;

int main(){
    int E=0,S=0,M=0;
    cin>>E>>S>>M;
    int cnt=0;
    int S_year=0;
    int E_year=0;
    int M_year=0;
    while(1){
        if(S==28)
        {
            S_year=cnt*28;
        }
        else{
            S_year=cnt*28+S;
        }
        
        E_year=S_year%15;
        if(E_year==0)E_year=15;
        M_year=S_year%19;
        if(M_year==0)M_year=19;

        if(E_year==E&&M_year==M&&S_year!=0)
            break;

        cnt++;
    }

    cout<<S_year<<endl;
}