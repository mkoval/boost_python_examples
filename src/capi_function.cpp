#include <Python.h>

static PyObject *py_hello_world(PyObject *self, PyObject *args)
{
    char const *const message = "Hello World";

    // Helper function for creating Python objects. The first argument is
    // similar to a format string, where "s" is a Python string.
    return Py_BuildValue("s", message);
}

// The module initialization function must be a C function.
extern "C" {

// This must be called "my<module_name>".
void initcapi_function()
{
    static PyMethodDef methods[] = {
        { "hello_world", py_hello_world, METH_VARARGS },
        { NULL, NULL },
    };
    Py_InitModule("capi_function", methods);
}

}
