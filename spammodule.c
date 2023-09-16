#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject* spam_double_decref(PyObject *self, PyObject *args) {
    printf("spam_double_decref ... begin\n");
    PyObject *obj = Py_BuildValue("s", "foobar");
    Py_DECREF (obj);
    Py_DECREF (obj); // Expect error, but does not error when using cpython built with `--with-pydebug`.
    printf("spam_double_decref ... end\n");
    Py_RETURN_NONE;
}

static PyMethodDef SpamMethods[] = {
    {"double_decref",  spam_double_decref, METH_VARARGS,
     "Test calling Py_DECREF twice."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "spam",   /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    SpamMethods
};

PyMODINIT_FUNC
PyInit_spam(void)
{
    return PyModule_Create(&spammodule);
}
