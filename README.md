## Spatial algorithms library for geometry.hpp

[![Build Status](https://travis-ci.com/mapbox/spatial-algorithms.svg?branch=master)](https://travis-ci.com/mapbox/spatial-algorithms)
[![codecov](https://codecov.io/gh/mapbox/spatial-algorithms/branch/master/graph/badge.svg)](https://codecov.io/gh/mapbox/spatial-algorithms)
[![hpp-skel](https://raw.githubusercontent.com/mapbox/cpp/master/assets/hpp-skel-badge_blue.svg)](https://github.com/mapbox/hpp-skel)

### Building

Spatial algorithms can be built using cmake. Please make sure you have a cmake version >= 3.3.

Example build and test

```
mkdir build
cd build
cmake ..
make -j
./test_sa
```

The `-Werror` flag is enabled by default, which turns compiler warnings into errors. You can disable like: `cmake -DWERROR=OFF ..`.

### Example Useage

```c++

#include <mapbox/geometry/geometry.hpp>
#include <mapbox/geometry/algorithms/predicates.hpp>
#include <iostream>

int main ()
{
    using namespace mapbox::geometry;
    line_string<double> line{ {70,50},{50,70}};
    polygon<double> poly {{{{0,0}, {100,0}, {100,100}, {0, 100}, {0,0}}},
        {{{25,25}, {25,75}, {75,75}, {75, 25}, {25,25} }}};

    std::cerr <<  "Intersects? " << algorithms::intersects(line, poly) << std::endl;
    std::cerr <<  "Disjoint? " << algorithms::disjoint(line, poly) << std::endl;

    // It should work with variant based `mapbox::geometry::geometry<T>` and all permutations also.

    geometry<double> g = line;

    std::cerr <<  "Intersects? " << algorithms::intersects(g, poly) << std::endl;
    std::cerr <<  "Disjoint? " << algorithms::disjoint(poly, g) << std::endl;
    return 0;
}

```
