#include <iostream>
#include <vector>
using namespace std;
void print_2d_vector(const vector<vector<int>>& vector_2d) {
    for (int i = 0; i < vector_2d.size(); i++) {
        for (int j = 0; j < vector_2d[i].size(); j++) {
            cout << vector_2d[i][j] << endl;
        }
    }
}

int main()
{
    vector <int> vec1;
    vector <int> vec2;
    vec1.push_back(10);
    vec1.push_back(20);
    cout<< vec1[0] << " "<< vec1[vec1.size()-1]<<endl;
    vec2.push_back(100);
    vec2.push_back(200);
    vector < vector < int>> vector_2d;
    vector_2d.push_back(vec1);
    vector_2d.push_back(vec2);
    print_2d_vector(vector_2d);
    cout<< endl;
    vec1[0] = 100;
    print_2d_vector(vector_2d);
    cout<<"Elemets of vector 1: "<<vec1[0]<<" "<<vec1[1]<<endl;
    return 0;
}
