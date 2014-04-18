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

struct Point {
    double x, y;
};

Point make_point(double x, double y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

struct Point_to_python {
    static PyObject *convert(Point const &pt)
    {
        using namespace boost::python;
        object py_pt = make_tuple(pt.x, pt.y);
        return incref(object(py_pt).ptr());
    }
};



BOOST_PYTHON_MODULE(bp_class)
{
    using namespace boost::python;
    def("hello_world", &hello_world);

    class_<HelloWorld>("HelloWorld")
        .def("hello", &HelloWorld::hello)
        .def("world", &HelloWorld::world)
        ;

    def("make_point", &make_point);

    to_python_converter<Point, Point_to_python>();
}
