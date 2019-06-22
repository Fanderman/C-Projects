#include "header.h"


double dystans(Punkt& p1, Punkt& p2){
    return sqrt((p1.Y() -p2.Y())*(p1.Y() -p2.Y()) + (p1.X() -p2.X())*(p1.X() -p2.X()));
}
