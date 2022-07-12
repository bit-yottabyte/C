//Athavan Jesunesan

#include "operations.h"

/*---- All the operations returning set ----*/

 Set& Set::operator+(const Set &rhs){
    for(int i = 0; i<256; i++){
        if(this->elements[i] == 1 || rhs.elements[i] == 1){
            this->elements[i] = 1;
        }
    }
    return *this;
} //Union

Set& Set::operator+(const int &other){
    this->elements[other] = 1;
    return *this;
} //Technically union; effectively 'add element'

Set& Set::operator-(const Set &other){

    for(int i = 0; i<256; i++){
        if(this->elements[i] == other.elements[i]){
            this->elements[i] = 0;
        }
    }
    return *this;
} //Difference

Set& Set::operator-(const int &other){
    this->elements[other] = 0;
    return *this;
} //Effectively 'remove element if present'

Set& Set::operator^(const Set &other){
    for(int i = 0; i<256; i++){
        if(this->elements[i] == 1 && other.elements[i] == 1){
            this->elements[i] = 1;
        }
        else{
            this->elements[i] = 0;
        }
    }
    return *this;
} //Intersection

Set& Set::operator^(const int &other){
    if(this->elements[other] == 1){
        this->elements[other] = 1;
    }
    else{
        this->elements[other] = 0;
    }
    return *this;
} //Intersection with element

Set& Set::operator~(){
    for(int i = 0; i<256; i++){
        if(this->elements[i]==1){
            this->elements[i] = 0;
        }
        else{
            this->elements[i] = 1;
        }
    }
    return *this;
} //Complement

Set Set::operator+(){
    Set s;
    for(int i = 0; i<256; i++){
        s.elements[i] = 1;
    }
    return s;
} //Set of universe

Set Set::operator-() const{
    Set s;
    return s;
} //Empty set

/*---- equality and ineqiality ----*/

bool Set::operator==(const Set &other){
    for(int i = 0; i<256; i++){
        if(this->elements[i] != other.elements[i]){
            return false;
        }
    }
    return true;
} //Test for set equality

bool Set::operator!=(const Set &other){
    for(int i = 0; i<256; i++){
        if(this->elements[i] == 1 && other.elements[i] != 1){
            return true;
        }
    }
    return false;
} //Test for set inequality

/* All operations that return booleans */

bool Set::operator<=(const Set &other){
    for(int i = 0; i<256; i++){
        if(this->elements[i] == 1 && other.elements[i] != 1){
            return false;
        }
    }
    return true;
} //Subset

bool Set::operator<(const Set &other){
    if(*this == other){ //if A=B then not strict subset
        return false;
    }
    for(int i = 0; i<256; i++){
        if(this->elements[i] == 1 && other.elements[i] != 1){
            return false;
        }
    }
    return true;
} //Strict Subset

bool Set::operator>=(const Set &other){
    for(int i = 0; i<256; i++){
        if(other.elements[i] == 1 && this->elements[i] != 1){
            return false;
        }
    }
    return true;
} //Superset

bool Set::operator>(const Set &other){
    if(*this == other){ //if A=B then not strict subset
        return false;
    }
    for(int i = 0; i<256; i++){
        if(other.elements[i] == 1 && this->elements[i] != 1){
            return false;
        }
    }
    return true;
} //Subset

bool Set::operator!(){
    return *this == -(*this); //if test is equal to the empty set
} //Test for empty set

int Set::operator()(){
    int card = 0;
    for(int i = 0; i<256; i++){
        if(this->elements[i] == 1){
            card++;
        }
    }
    return card;
} //Cardinality of set. i.e. |Set|

bool Set::operator[](const int &pos){
    if(this->elements[pos] == 1){
        return true;
    }
    return false;
} //Test for 'is element of'

std::ostream& operator<<(std::ostream &out, const Set &s){
    for(int i = 0; i<256; i++){
        out << s.elements[i] << " ";
    }
    out << std::endl;
    return out;
}

std::istream& operator>>(std::istream &in, Set &s){
    for(int i = 0; i<256; i++){
        in >> s.elements[i];
    }
    return in;
}


