#include "Cadbury.h"
#include "DairyMilk.h"
#include "DairyMilkBubbly.h"

Chocolate *Cadbury::createChocolate(bool slab) {
    return new DairyMilk(slab);
}

AeratedChocolate *Cadbury::createAeratedChocolate(int bubblespccm) {
    return new DairyMilkBubbly(bubblespccm);
}
