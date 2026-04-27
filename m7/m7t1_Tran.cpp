#include <iostream>
using namespace std;

// CSC 134
// M7T1 - Restaurant Rating
// Justin Tran
// 4/27/24
// Use Restaurant class to store user ratings

// Next time we'll put the class in a separate file
class Restaurant {
  private:
    string name;    // the name
    double rating;  // 0 to 5 stars

  public:
	// constructor 
	Restaurant(string n, double r) {
		name = n;
		rating = r;
	}
	// getters and setters
    void setName(string n) {
        name = n; 
    }
    void setRating(double r) {
        rating = r;
    }
    string getName() const {
        return name;
    }
    double getRating() const {
        return rating;
    }
  
};

int main() {
    cout << "M7T1 - Restaurant Reviews" << endl;

    string name;
    double rating;

    cout << "Enter restaurant name: ";
    getline(cin, name);
    cout << "Enter rating: ";
    cin >> rating;

    Restaurant rest1 = Restaurant(name, rating);
    cout << rest1.getName() << endl;
    cout << rest1.getRating() << endl;

    return 0;

}