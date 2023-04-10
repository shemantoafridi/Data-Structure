#include <iostream>
using namespace std;

int mdc(int a, int b) {
    if(b==0) return a;
    else return mdc(b, a%b);
}

int main() {
	int n, n1, n2, d1, d2, fn, fd, d, len;
	char op;
	string line;
	cin>>n;

	while(n--) {
        cin>>n1;
        cin.ignore();
        cin.ignore();
        cin>>d1>>op>>n2;
        cin.ignore();
        cin.ignore();
        cin>>d2;

		if(op=='+') {
			fn=(n1*d2 + n2*d1);
			fd=(d1*d2);
		}

		else if(op=='-') {
			fn=(n1*d2 - n2*d1);
			fd=(d1*d2);
		}

		else if(op=='*') {
			fn=(n1*n2);
			fd=(d1*d2);
		}

		else if(op=='/') {
			fn=(n1*d2);
			fd=(n2*d1);
		}

		d=mdc(fn,fd);
		if(d<0) d = -d;
        cout<<fn<<"/"<<fd<<" = "<<(fn/d)<<"/"<<(fd/d)<<"\n";
	}
	return 0;
}
