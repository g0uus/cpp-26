//
//
//

#include "grh_version.h"
//
#include <iostream>
#include <print>
#include <cmath>
#include "concept1.h"
#include "concept2.h"
#include "picture.h"

using std::cout;
using std::println;

DISPLAY_GCC_VERSION
DISPLAY_CPP_VERSION

//
class C1
{
public:
    void test() = delete;//("DO NOT USE!"); // Clang-Tidy doesn't recognise this :(
};

template <typename T, typename... Types>
void printer(T t, Types... args)
{
    std::cout << t << '\n';
    if constexpr (sizeof...(args) > 0)
    {
        printer(args...);
    }
}

int concept1()
{
    std::vector ints{1, 2, 3, 4, 5};

    const auto rslt = Average(ints);
    std::cout << Average(ints) << '\n';

    return rslt;
}

void concept2()
{
    myContainer<std::string> c1("Hello Concepts!");
    myContainer<int> c2(42);
    myContainer<double> c3(M_PI);

    std::cout << c1.get() << '\n';
    std::cout << c2.get() << '\n';
    std::cout << c3.get() << '\n';

    myContainer<float> c4(M_PIf); // Error: no matching function for call to 'myContainer<float>::get() const'
    //const auto x = c4.get();
    std::cout << c4.get() << '\n';

}

void PicTest()
{

    Picture pic;

    pic.insert<Circle>(Coord(1.0, 2.0), 3.0); // NOLINT
    pic.insert<Rectangle>(Coord(4.0, 5.0), 6.0, 7.0); // NOLINT

    // pic.insert<int>(42); // Error: static assertion failed: T must be a GeoObj type
    pic.draw();
}

int main()
{
    cout << "Hello World\n";

    println("Hello world 2");

    printer('1', "foo", 42);

    printer("Average of ints is", concept1());

    {
        C1 c1 [[maybe_unused]];
        // c1.test();
    }


    constexpr auto a1 = 1'000'000;
    cout << "a1: " << a1 << '\n';

    concept2();

    PicTest();

    //
}
