#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Movie {
private:
    string name;
    int movieNumber;
    string rating;
    static vector<int> views;

public:
    // Constructor
    Movie(string n = "", string r = "")
        : name(n), rating(r), movieNumber(views.size()) {
            //Resize views
        views.resize(movieNumber + 1, 0);
    }

    // Getters and Setters
    string getName() const { return name; }
    void setName(const string& newName) { name = newName; }

    string getRating() const { return rating; }
    void setRating(const string& newRating) { rating = newRating; }

    int getNumber() const { return movieNumber; }

    static vector<int> getViewsList() { return views; }
    static void setViews(const vector<int>& newViews) { views = newViews; }

    static void increaseViewCount(int index, int addViews = 1) {
        if (index >= 0 && index < views.size()) {
            views[index] += addViews;
        } else {
            throw out_of_range("Error: Index is out of bounds for 'views' vector");
        }
    }

    static int printViews(int index) {
        if (index >= 0 && index < views.size()) {
            return views[index];
        } else {
            throw out_of_range("Error: Index is out of bounds for 'views' vector");
        }
    }
};

// Static vector initialization
vector<int> Movie::views;

int main() {
    // Movies
    Movie movie1("Inception", "PG-13");
    Movie movie2("The Incredible Hulk", "PG-13");
    Movie movie3("Deadpool & Wolverine", "R");

    // Movie vector
    vector<Movie> movies = {movie1, movie2, movie3};

    // Increment views and print details
    for (int i = 0; i < movies.size(); i++) {
        Movie::increaseViewCount(i, (i + 1) * 10000000); // Increment views for the movie
        cout << movies[i].getName() << " has a record-breaking number of views! It has reached "
             << Movie::printViews(i) << " viewers worldwide!" << endl;
    }

    return 0;
}
