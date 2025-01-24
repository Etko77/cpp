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
        Mystring operator+=(const Mystring &obj){
            char* buff = new char[strlen(this->str)+strlen(obj.str)+1];
            strcpy(buff,this->str);
            strcat(buff,obj.str);
            delete [] this->str;
            this->str = buff;
            return *this;

        }
        Mystring operator*(const int num){
            if (num <= 0) {
                return Mystring{""}; 
            }
            char* buff = new char[strlen(this->str)*num+1];
            strcpy(buff,this->str);
            for(size_t i = 0; i<(num-1);i++){
                strcat(buff,this->str);
            }
            Mystring temp{buff};
            delete [] buff;
            return temp;
        }
        Mystring operator*=(const int num){
            char* buff = new char[strlen(this->str)*num+1];
            strcpy(buff,this->str);
            for(size_t i = 0; i < (num-1);i++){
                strcat(buff,this->str);
            }
            delete [] this->str;
            this->str = buff;
            return *this;
        }
        bool operator>(const Mystring &rso){
            if(strlen(this->str)>strlen(rso.str)){
                return true;
            }else{
                return false;
            }
        }
        bool operator<(const Mystring &rso){
            if(strlen(this->str)<strlen(rso.str)){
                return true;
            }else{
                return false;
            }
        }
        
        void display(){
            cout<< str<<endl;
        }
        


};

int main(){
    Mystring alfredo{"Alfredo"};
    Mystring alberto{"Alberto"};
    Mystring alfredoMartini{"Alfredo"};
    //Checking == operator manipulation
    cout << (alfredo == alfredoMartini) << endl;
    alfredo.display();
    //checking operator - manipulation
    alfredo = -alfredo;
    alfredo.display();
    Mystring bob;
    //Checking insertion and extraction operator manipulation
    cout<<"Enter a string for the object bob:"<<endl;
    cin >> bob;
    cout<<bob<<" has entered the game"<<endl;
    //Checking operator+= manipulation
    bob += alberto;
    bob.display();
    //Checking operator* manipulation
    Mystring bobei = bob * 3;
    bobei.display();
    //Checking operator *= manipulation
    alfredo *=3;
    alfredo.display();
    cout<<"ALfredo greater than Etienne: "<<(alfredo>bobei)<<endl;
    cout<<"ALfredo lesser than Etienne: "<<(alfredo<bobei)<<endl;
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
