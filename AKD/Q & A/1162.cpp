#include <iostream>
using namespace std;

int main() {
    int n, m, c, i, j;
    cin>>n;

    while(n--) {
        cin>>m;
        int carriages[m];
        for(i=0; i<m; i++) {
            cin>>carriages[i];
        }
        c=0;
        for(i=0; i<m; i++) {
            for(j=i+1; j<m; j++) {
                if(carriages[i]>carriages[j]) {
                    swap(carriages[i],carriages[j]);
                    c++;
                }
            }
        }
        cout<<"Optimal train swapping takes "<<c<<" swaps.\n";
    }
    return 0;
}
