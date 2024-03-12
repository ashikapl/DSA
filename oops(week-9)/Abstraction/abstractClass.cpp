#include <iostream>
#include "Bird.h"
using namespace std;

void aboutDiffBirds(Bird *&bird)
{
    bird->eat();
    bird->fly();
}

int main()
{
    Bird *bird = new Eagle();
    aboutDiffBirds(bird);

    // Bird * b2 = new Bird(); // this implementation is wrong

    return 0;
}