#include "Nestle.h"
#include "MilkyBar.h"
#include "Aero.h"

Chocolate *Nestle::createChocolate(bool slab) {
    return new MilkyBar(slab);
}

AeratedChocolate *Nestle::createAeratedChocolate(int bubblespccm) {
    return new Aero(bubblespccm);
}
