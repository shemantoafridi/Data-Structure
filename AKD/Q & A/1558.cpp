#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, i, root, sum;
    bool temp;

    while(cin>>n) {
        temp=false;
        root=sqrt(n);
        i=0;
        while(root>=i){
            sum=pow(i,2)+pow(root,2);
            if(sum==n){
                temp=true;
                break;
            }
            else if(sum<n) i++;
            else root--;
        }

        if(temp) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
