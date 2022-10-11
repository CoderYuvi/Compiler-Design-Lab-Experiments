#include <iostream>
using namespace std;


int main(){
    int n;
    cout<<"Enter total number of productions: ";
    cin>>n;
    string prod[n],firstof[n];
    
    cout<<"\nEnter productions in the form of A->B where A is a non terminal and B can be a terminal or non-terminal...\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<". ";
        cin>>prod[i];
        if(prod[i][1]=='-'&&prod[i][2]=='>')
        continue;
        else
        {cout<<"<---  Error :( Enter production in the given format of A->B  --->\n";i--;}
        
    }
    cout<<"Success\n\nThe productions are...\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<". ";
        cout<<prod[i]<<"\n";
    }
    
        
    return 0;
}