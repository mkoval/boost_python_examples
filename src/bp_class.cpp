#include <string>
#include <boost/python.hpp>

static std::string hello_world()
{
    return "Hello World";
}

BOOST_PYTHON_MODULE(bp_class)
{
    //using namespace boost::python;
    //def("hello_world", &hello_world);
}
