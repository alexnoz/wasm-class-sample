#ifndef DOG_H
#define DOG_H

#include <string>

using std::string;

class Dog {
  string name;

  public:
    Dog (string n);
    string getGreeting ();
    void makeSound ();
};

#endif
