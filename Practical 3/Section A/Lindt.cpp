#include "Lindt.h"
#include "Lindor.h"

Chocolate *Lindt::createChocolate(bool slab) {
    return new Lindor(slab);
}
