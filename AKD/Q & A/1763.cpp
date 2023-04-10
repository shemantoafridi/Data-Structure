#include <iostream>
using namespace std;

int main() {
    string data[]={"estados-unidos", "inglaterra", "australia", "antardida", "canada",
                    "espanha", "argentina", "chile", "mexico", "italia", "libia",
                    "siria", "marrocos", "brasil", "portugal", "alemanha", "austria",
                    "coreia", "grecia", "suecia", "turquia", "irlanda", "belgica",
                    "japao"};
    int len=sizeof(data)/sizeof(data[0]);
    string country;
    while(cin>>country) {
        for(int i=0; i<len; i++) {
            if(data[i].compare(country)==0) {
                if(i>=0 && i<5) {
                    cout<<"Merry Christmas!\n";
                    break;
                }
                else if(i>=5 && i<9) {
                    cout<<"Feliz Navidad!\n";
                    break;
                }
                else if(i>=9 && i<11) {
                    cout<<"Buon Natale!\n";
                    break;
                }
                else if(i>=11 && i<13) {
                    cout<<"Milad Mubarak!\n";
                    break;
                }
                else if(i>=11 && i<15) {
                    cout<<"Feliz Natal!\n";
                    break;
                }
                else if(i==15) {
                    cout<<"Frohliche Weihnachten!\n";
                    break;
                }
                else if(i==16) {
                    cout<<"Frohe Weihnacht!\n";
                    break;
                }
                else if(i==17) {
                    cout<<"Chuk Sung Tan!\n";
                    break;
                }
                else if(i==18) {
                    cout<<"Kala Christougena!\n";
                    break;
                }
                else if(i==19) {
                    cout<<"God Jul!\n";
                    break;
                }
                else if(i==20) {
                    cout<<"Mutlu Noeller\n";
                    break;
                }
                else if(i==21) {
                    cout<<"Nollaig Shona Dhuit!\n";
                    break;
                }
                else if(i==22) {
                    cout<<"Zalig Kerstfeest!\n";
                    break;
                }
                else if(i==23) {
                    cout<<"Merii Kurisumasu!\n";
                    break;
                }
            }
            else if(i+1==len){
                cout<<"--- NOT FOUND ---\n";
            }
        }
    }
    return 0;
}
