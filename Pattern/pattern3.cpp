#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int row=1;
    while(row<=n){
        int count=row;
        int col=1;
        while(col<=row){
            cout<<count<<" ";
            count+=1;
            col++;
        }cout<<endl;
        row++;
    }

    return 0;
}