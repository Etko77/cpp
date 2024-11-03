#include <iostream>
using namespace std;

int main(){
    int grades [5];
    cout << "Enter grades : ";
    cin >> grades[0];
    cin >> grades[1];
    cin >> grades[2];
    cin >> grades[3];
    cin >> grades[4];
    for (int i = 0; i < (sizeof(grades)/4); i++)
    {
        cout <<"Grade "<<i+1<<" "<<grades[i]<<endl;
    }

    
    
    return 0;
}