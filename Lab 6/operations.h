//Athavan Jesunesan

#include <iostream>
//Reminder: http://en.cppreference.com/w/cpp/language/operators

class Set {
private:
	bool elements[256];
	Set(const bool elements[256]); //Helpful for immutable types
public:
	Set(): elements {false} {}

	Set& operator+(const Set &other); //Union
	Set& operator+(const int &other); //Technically union; effectively 'add element'
	Set& operator-(const Set &other); //Difference
	Set& operator-(const int &other); //Effectively 'remove element if present'
	Set& operator^(const Set &other); //Intersection
	Set& operator^(const int &other); //Intersection with element
	Set& operator~(); //Complement

	Set operator+(); //Set of universe
	Set operator-() const; //Empty set

    bool operator==(const Set &other); //Test for set equality
	bool operator!=(const Set &other); //Test for set inequality

	bool operator<=(const Set &other); //Subset
	bool operator<(const Set &other); //Strict subset
	bool operator>=(const Set &other); //Superset
	bool operator>(const Set &other); //Strict superset
	bool operator!(); //Test for empty set

	int operator()(); //Cardinality of set. i.e. |Set|
	bool operator[](const int &pos); //Test for 'is element of'

	friend std::ostream& operator<<(std::ostream &out, const Set &s);
	friend std::istream& operator>>(std::istream &in, Set &s);
};
