using namespace std;
#include <iostream>
#include <vector>
#include <cstring>

class Mystring{
    private:
        char* str;
    public:
        Mystring(const char * s){
            str = new char[strlen(s)+1];
            strcpy(str,s);
        }
        ~Mystring(){
            delete[] str;
        }

        bool operator==(const Mystring& rhs) const{
            if (strcmp(this->str,rhs.str)==0){
                return true;
            }else{
                return false;
            }
        }
        friend ostream& operator<<(ostream& os, const Mystring& myStr){
            os << myStr.str;
            return os;
        }
        


};

int main(){
    Mystring alfredo{"Alfredo"};
    Mystring alberto{"Alberto"};
    Mystring alfredoMartini{"Alfredo"};
    cout << (alfredo == alfredoMartini) << endl;

    return 0;
}