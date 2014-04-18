#include <string>
#include <boost/python.hpp>

class HelloWorld {
public:
    std::string hello() const { return "Hello"; }
    std::string world() const { return "World"; }
};

static std::string hello_world()
{
    return "Hello World";
}

BOOST_PYTHON_MODULE(bp_class)
{
    using namespace boost::python;
    def("hello_world", &hello_world);

    class_<HelloWorld>("HelloWorld")
        .def("hello", &HelloWorld::hello)
        .def("world", &HelloWorld::world)
        ;
}
