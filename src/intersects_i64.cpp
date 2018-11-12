//
#include <mapbox/geometry/algorithms/detail/instantiate_macro.hpp>
#include <mapbox/geometry/algorithms/predicates/intersects_impl.hpp>

namespace mapbox { namespace geometry { namespace algorithms {

MAPBOX_ALGORITHM_INSTANTIATE(INTERSECTS,
                             point<std::int64_t>,
                             line_string<std::int64_t>,
                             polygon<std::int64_t>,
                             multi_point<std::int64_t>,
                             geometry<std::int64_t>)
} // namespace algorithms
} // namespace geometry
} // namespace mapbox
