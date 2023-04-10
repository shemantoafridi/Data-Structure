#include <iostream>
#include <algorithm>
using namespace std;

struct chars {
    int ascii;
    int c;
    bool operator < (const chars& another) const {
        if(c!=another.c) return c<another.c;
        return another.ascii<ascii;
    }
};

void frequencies(string str) {
    int i, j, k=0, c=1;
    int len=str.length();
    chars fr[len];
    sort(str.begin(), str.end());
    char temp=str[0];
    for(i=1; i<len; i++){
        if(temp==str[i]){
            c++;
        }
        else{
            fr[k].ascii = temp;
            fr[k].c = c;
            temp=str[i];
            c=1;
            k++;
        }
    }
    fr[k].ascii=temp;
    fr[k].c=c;
    k++;

    sort(fr, fr+k);

    for(i=0; i<k; i++) {
        cout<<fr[i].ascii<<" "<<fr[i].c<<"\n";
    }
}

int main() {
    bool t=false;
    string str;
    while(cin>>str) {
        if(t) {
            cout<<"\n";
        }
        frequencies(str);
        t=true;
    }
    return 0;
}
