
#include <iostream>
#include <conio.h>
using namespace std;

void sortString(string line) {
    int i, l=0, j=0, k, max, tm=0, mi, length=line.length(), len[1000], start[1000], end[1000];
    bool first=true;

    for(i=0; i<length; i++) {
        if(line[i]!=' '){
            l++;
            if(first) {
                start[j]=i;
                first=false;
            }
        }
        if(line[i]==' ' || i+1==length){
            end[j]=i-1;
            len[j]=l;
            l=0;
            j++;
            first=true;
        }
    }
    end[j-1]++;

    for(k=0; k<j; k++) {
        max=-1;
        for(i=0; i<j; i++) {
            if(len[i]>max) {
                max=len[i];
                mi=i;
            }
        }
        len[mi]=-1;
        if(max==-1) {
            break;
        }
        for(i=start[mi]; i<=end[mi]; i++) {
            cout<<line[i];
        }
        if(k+1!=j) {
            cout<<" ";
        }
    }
    cout<<"\n";
}

int main() {
    int n, i;
    string line;
    cin>>n;
    cin.ignore();
    //getchar();
    for(i=0; i<n; i++) {
        getline(cin, line);
        sortString(line);
    }
    return 0;
}
