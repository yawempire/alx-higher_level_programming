#include <Python.h>
#include <stdio.h>

void print_python_list(PyObject *p) {
    // Check if p is a Python list
    if (!PyList_Check(p)) {
        fprintf(stderr, "Invalid Python list object\n");
        return;
    }

    // Get the number of elements in the list
    Py_ssize_t size = PyList_Size(p);

    // Get the allocated size of the list
    Py_ssize_t allocated = ((PyListObject *)p)->allocated;

    // Print basic information about the list
    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", allocated);

    // Iterate over the list to print each element's type
    for (Py_ssize_t i = 0; i < size; i++) {
        PyObject *item = PyList_GetItem(p, i);
        const char *typeName = Py_TYPE(item)->tp_name;
        printf("Element %ld: %s\n", i, typeName);
    }
}
#include <Python.h>
#include <stdio.h>

void print_python_bytes(PyObject *p) {
    // Check if p is a Python bytes object
    if (!PyBytes_Check(p)) {
        fprintf(stderr, "[ERROR] Invalid Bytes object\n");
        return;
    }

    // Get the size of the bytes object
    Py_ssize_t size = PyBytes_Size(p);

    // Print basic information about the bytes object
    printf("[.] bytes object info\n");
    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", PyBytes_AsString(p));

    // Print up to 10 bytes from the object
    printf("  first 10 bytes: ");
    for (Py_ssize_t i = 0; i < size && i < 10; i++) {
        printf("%02x", (unsigned char)PyBytes_AsString(p)[i]);
        if (i < 9 && i + 1 < size) {
            printf(" ");
        }
    }
    printf("\n");
}
