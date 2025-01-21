using namespace std;
#include <iostream>
#include <vector>
#include <cstring>

class Mystring{

    friend ostream &operator<<(ostream &os, const Mystring &rso);
    friend istream &operator>>(istream &in, Mystring &rso);
    private:
        char* str;
    public:

        Mystring(){
            str = new char[1];
            str[0] = '\0';
        }
        Mystring(const char * s){
            str = new char[strlen(s)+1];
            strcpy(str,s);
        }
        Mystring(const Mystring &other){
            str = new char[strlen(other.str)+1];
            strcpy(str,other.str);

        }
        Mystring& operator=(const Mystring &other) { 
        if (this != &other) {
            delete[] str; 
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
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
        Mystring operator+(const Mystring &rhs){
            size_t buffSize = strlen(this->str)+strlen(rhs.str)+1;
            char* buff = new char[buffSize];
            strcpy(buff,this->str);
            strcat(buff,rhs.str);
            Mystring temp {buff};
            delete [] buff;
            return temp;
            
        }
        Mystring operator-(){
            char* buff = new char[strlen(this->str)+1];
            strcpy(buff,this->str);
            for(size_t i = 0;i<strlen(buff);i++){
                buff[i] = tolower(buff[i]);
            }
            Mystring temp{buff};
            delete [] buff;
            return temp;

        }
        
        void display(){
            cout<< str<<endl;
        }
        


};

int main(){
    Mystring alfredo{"Alfredo"};
    Mystring alberto{"Alberto"};
    Mystring alfredoMartini{"Alfredo"};
    cout << (alfredo == alfredoMartini) << endl;
    alfredo.display();
    // alfredo = -alfredo;
    // alfredo.display();
    Mystring bob;
    cout<<"Enter a string for the object bob:"<<endl;
    cin >> bob;
    cout<<"Bob has entered the game "<<bob<<endl;
    return 0;
}

//extraction operator
ostream &operator<<(ostream &os, const Mystring &rhs){
    os << rhs.str;
    return os;
};
//insertion operator
istream &operator>>(istream &in, Mystring &rhs){
    char* buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
};
