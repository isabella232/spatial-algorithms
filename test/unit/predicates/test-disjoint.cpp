#include <catch.hpp>
#include <mapbox/geometry.hpp>
#include <mapbox/geometry/algorithms/predicates.hpp>

template <typename T>
void test_disjoint()
{
    using namespace mapbox::geometry;
    namespace op = algorithms;
    SECTION("Point/Point")
    {
        point<T> p1{100, 200};
        point<T> p2{100, 201};
        geometry<T> g1 = p1;
        geometry<T> g2 = p2;
        // p1
        CHECK(op::disjoint(p1, p2));
        CHECK(op::disjoint(p1, g2));
        // g1
        CHECK(op::disjoint(g1, p2));
        CHECK(op::disjoint(g1, g2));
        // p2
        CHECK(op::disjoint(p2, p1));
        CHECK(op::disjoint(p2, g1));
    }

    SECTION("Point/LineString")
    {
        point<T> p1{150, 151};
        line_string<T> l2{{100, 100}, {200, 200}};
        geometry<T> g1 = p1;
        geometry<T> g2 = l2;
        // p1
        CHECK(op::disjoint(p1, l2));
        CHECK(op::disjoint(p1, g2));
        // g1
        CHECK(op::disjoint(g1, l2));
        CHECK(op::disjoint(g1, g2));
        // l2
        CHECK(op::disjoint(l2, p1));
        CHECK(op::disjoint(l2, g1));
        // g2
        CHECK(!op::disjoint(g2, l2));
        CHECK(op::disjoint(g2, g1));
    }

    // TODO(danespringmeyer): add missing permutations !!!!!

    SECTION("LineString/Polygon")
    {
        line_string<T> l1{{30, 70}, {70, 30}};
        geometry<T> g1 = l1;

        linear_ring<T> exterior = {{0, 0}, {100, 0}, {100, 100}, {0, 100}, {0, 0}};
        linear_ring<T> interior = {{25, 25}, {25, 75}, {75, 75}, {75, 25}, {25, 25}};
        polygon<T> poly = {{exterior}, {interior}};

        CHECK(op::disjoint(l1, poly));
        CHECK(op::disjoint(poly, l1));
        geometry<T> g2 = poly;
        CHECK(op::disjoint(g1, g2));
        CHECK(op::disjoint(g2, g1));
    }

    SECTION("MultiPoint/Point")
    {
        auto mp = multi_point<T>{{100, 100}, {200, 100}, {300, 100}};
        auto p = point<T>{201, 100};
        geometry<T> g1 = mp;
        geometry<T> g2 = p;
        CHECK(op::disjoint(mp, p));
        CHECK(op::disjoint(p, mp));
        CHECK(op::disjoint(g1, g2));
        CHECK(op::disjoint(g2, g1));
    }

    SECTION("MultiPoint/MultiPoint")
    {
        geometry<T> g1 = multi_point<T>{{200, 200}, {100, 101}, {300, 300}};
        geometry<T> g2 = multi_point<T>{{100, 100}, {200, 100}, {300, 100}};
        CHECK(op::disjoint(g1, g2));
    }

    SECTION("MultiPoint/LineString")
    {
        geometry<T> g1 = multi_point<T>{{200, 200}, {100, 101}, {300, 300}};
        geometry<T> g2 = line_string<T>{{100, 100}, {200, 100}, {300, 100}};
        CHECK(op::disjoint(g1, g2));
        CHECK(op::disjoint(g2, g1));
    }
}

TEST_CASE("disjoint double")
{
    test_disjoint<double>();
}

TEST_CASE("disjoint int64_t")
{
    test_disjoint<std::int64_t>();
}
