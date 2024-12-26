#include <iostream>
using namespace std;

class MyClass{
    private:
        int* data;
        int size;
    public:
        MyClass(int s): size(s),data(new int[s]){
            cout<<"Constructor Allocated "<<size<<" int's"<<endl;
        }

        //Move constructor
        MyClass(MyClass&& other) noexcept: data(other.data),size(other.size){
            other.data = nullptr;
            other.size = 0;
            cout<<"Recources have been moved to the new object"<<endl;
        }
        //Destructor
        ~MyClass(){
            delete[]data;
            cout<<"Destructor data has been cleaned off the heap storage memory";
        }
        int get_size(){return size;};
};

int main()
{
    MyClass classObject1(10);
    MyClass classObject2(move(classObject1));
    cout<<classObject2.get_size()<<endl;
    
    return 0;
}