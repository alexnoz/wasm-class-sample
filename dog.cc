#include <iostream>
#include <string>

#include "dog.h"
#include "emscripten/bind.h"

using namespace emscripten;
using namespace std;

Dog::Dog(string n): name(n) {}

string Dog::getGreeting () {
  return "My name is " + name + ", hello from C++!";
}

void Dog::makeSound () {
  cout << "bark!" << '\n';
}

EMSCRIPTEN_BINDINGS (c) {
  class_<Dog>("Dog")
    .constructor<string>()
    .function("makeSound", &Dog::makeSound)
    .function("getGreeting", &Dog::getGreeting);
}
