#include <iostream>
#include <string>
#include <Python.h>

struct HelloWorld_wrapper {
    PyObject_HEAD
};

static PyTypeObject HelloWorld_type = {
    PyObject_HEAD_INIT(NULL)
    0,                               // ob_size = must always be zero
    "capi_class.HelloWorld",         // tp_name = name of the class in Python
    sizeof(HelloWorld_wrapper),      // tp_basicsize
    NULL,                            // tp_itemsize
    NULL,                            // tp_dealloc
    NULL,                            // tp_print
    NULL,                            // tp_getattr
    NULL,                            // tp_setattr
    NULL,                            // tp_compare
    NULL,                            // tp_repr
    NULL,                            // tp_as_number
    NULL,                            // tp_as_sequence
    NULL,                            // tp_as_mapping
    NULL,                            // tp_hash
    NULL,                            // tp_call
    NULL,                            // tp_str
    NULL,                            // tp_getattro
    NULL,                            // tp_setattro
    NULL,                            // tp_as_buffer
    Py_TPFLAGS_DEFAULT,              // tp_flags
    "Class wrapped with the C API.", // tp_doc
};

extern "C" {

void initcapi_class()
{
    // Default __new__ function that takes care of memory allocation. You will
    // likely need to override this with a custom allocator.
    HelloWorld_type.tp_new = PyType_GenericNew;

    // Finishes initializing the type. Using the type will SEGFAULT if you
    // don't do this!
    if (PyType_Ready(&HelloWorld_type) < 0) {
        std::cerr << "Something went wrong!" << std::endl;
        return;
    }

    // Create the "capi_class" Python module.
    static PyMethodDef module_methods[] = {
        { NULL, NULL },
    };
    PyObject *module = Py_InitModule3("capi_class", module_methods,
                                      "Module wrapped with the C API.");

    // Create the "HelloWorld" Python class. We need to manually increment the
    // reference counter so the type doesn't get immediately garbage collected.
    Py_INCREF(&HelloWorld_type);
    PyModule_AddObject(module, "HelloWorld", (PyObject *) &HelloWorld_type);

    // We haven't even added any methods yet!
}

}
