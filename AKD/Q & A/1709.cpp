#include <iostream>
using namespace std;

int main() {
    int n, pack=2, i;
    cin>>n;

    for(i=1; pack!=1; i++) {
        if(pack<=n/2) pack+=pack;
        else pack-=(n-pack+1);
    }

    cout<<i<<"\n";
    return 0;
}
