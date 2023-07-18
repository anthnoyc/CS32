//
//  main.cpp
//  RainfallList
//
//  Created by Anthony Chen on 4/17/23.
//

#include <iostream>
#include "RainfallList.h"
#include "Sequence.h"
#include <cassert>

int main() {
    RainfallList r;
        assert(r.size() == 0);
        assert(r.add(23));
        assert(r.size() == 1);
        assert(r.remove(2) == false);
        assert(r.remove(23) == true);
        assert(r.minimum() == NO_RAINFALLS);
        assert(r.maximum() == NO_RAINFALLS);
        assert(r.add(23));
        assert(r.add(2));
        assert(r.add(3));
        assert(r.size() == 3);
        assert(r.minimum() == 2);
        assert(r.maximum() == 23);
        assert(r.add(-1) == false);
        assert(r.add(401) == false);
        assert(r.remove(401) == false);
        assert(r.add(23) == true);
        assert(r.add(23) == true);
        assert(r.size() == 5);
        assert(r.remove(23) == true);
        assert(r.remove(23) == true);
        assert(r.size() == 3);
    std::cerr << "passed" << std::endl;
    return 0;
}
