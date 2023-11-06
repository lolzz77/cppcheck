#include <stdio.h>
#include <pthread.h>

// Test library configuration for python.cfg
//
// Usage:
// $ cppcheck --check-library --library=python --enable=style,information --inconclusive --error-exitcode=1 --disable=missingInclude --inline-suppr test/cfg/python.c
// =>
// No warnings about bad library configuration, unmatched suppressions, etc. exitcode=0
//

#define PY_SSIZE_T_CLEAN
#include <Python.h> // should be the first include
#include <stdio.h>

void validCode(PyObject * pPyObjArg)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    PyObject * pPyObjNULL = NULL;
    Py_Initialize();
    Py_INCREF(pPyObjArg);
    Py_DECREF(pPyObjArg);
    Py_XINCREF(pPyObjArg);
    Py_XINCREF(pPyObjNULL);
    Py_XDECREF(pPyObjArg);
    Py_XDECREF(pPyObjNULL);
    Py_CLEAR(pPyObjArg);
    Py_CLEAR(pPyObjNULL);
    (void)PyErr_NewException("text", NULL, NULL);

    // cppcheck-suppress unusedAllocatedMemory
    char * pBuf1 = PyMem_Malloc(5);
    PyMem_Free(pBuf1);
    // cppcheck-suppress unusedAllocatedMemory
    int * pIntBuf1 = PyMem_New(int, 10);
    PyMem_Free(pIntBuf1);
}

void nullPointer()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    // cppcheck-suppress nullPointer
    Py_INCREF(NULL);
    // cppcheck-suppress nullPointer
    Py_DECREF(NULL);
}

void PyMem_Malloc_memleak()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    const char * pBuf1 = PyMem_Malloc(1);
    printf("%p", pBuf1);
    // cppcheck-suppress memleak
}

void PyMem_Malloc_mismatchAllocDealloc()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    // cppcheck-suppress unusedAllocatedMemory
    char * pBuf1 = PyMem_Malloc(10);
    // cppcheck-suppress mismatchAllocDealloc
    free(pBuf1);
}

void PyMem_New_memleak()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    const char * pBuf1 = PyMem_New(char, 5);
    printf("%p", pBuf1);
    // cppcheck-suppress memleak
}
