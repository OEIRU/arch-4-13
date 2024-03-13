#define _USE_MATH_DEFINES
#include <iostream>
#include "C:\Users\????\AppData\Local\Programs\Python\Python310\include\Python.h"
#include <math.h>
using namespace std;

const double eps = 0.001;

double func(double x, double a, double b) {
    return sqrt((1 - a * pow(x, 2)) / b);
}

static PyObject* square_square(PyObject* self, PyObject* args) {
	PyObject* listObj;
    if (!PyArg_ParseTuple(args, "O", &listObj)) {
        return NULL;
    }
	double A = PyFloat_AsDouble(PyList_GetItem(PyList_GetItem(listObj, 0), 0));
	double B = PyFloat_AsDouble(PyList_GetItem(PyList_GetItem(listObj, 1), 1));
	double x1 = -1 / sqrt(A), x2 = 1 / sqrt(A), n = (x2 - x1) / eps;
    double I = eps * (func(x1, A, B) + func(x2, A, B)) / 6.0;
    for (int i = 1; i <= n; ++i) {
        if (i <= (n - 1)) {
            I += +2.0 / 6.0 * eps * func(x1 + eps * i, A, B);
        }
        I += 4.0 / 6.0 * eps * func(x1 + eps * (i - 0.5), A, B);
    }
    return PyFloat_FromDouble(2*I);
}

int* sort(int list[], int start, int finish) {
	int left = start, right = finish;
	int pivot = list[(left + right) / 2];
	while (left <= right) {
		while (list[left] < pivot) {
			left++;
		}
		while (list[right] > pivot) {
			right--;
		}
		if (left <= right) {
			swap(list[left++], list[right--]);
		}
	}
	if (start < right) {
		sort(list, start, right);
	}	
	if (finish > left){
		sort(list, left, finish);
	}
	return list;
}

static PyObject* square_sort(PyObject* self, PyObject* args) {
	PyObject* listObj;
	int start, finish;
	if (!PyArg_ParseTuple(args, "Oii", &listObj, &start, &finish)) {
		return NULL;
	}

	int* list = new int[finish];
	for (int i = start; i < finish; ++i) {
		list[i] = PyLong_AsLong(PyList_GetItem(listObj, i));
	}

	auto result = sort(list, start, finish);

	PyObject* dlist = PyList_New(finish);
	for (int i = start; i < finish; ++i) {
		PyList_SetItem(dlist, i, PyLong_FromLong(result[i]));
	}

	return dlist;
}

static PyObject* square_area(PyObject* self, PyObject* args) {
	PyObject* listObj;
	if (!PyArg_ParseTuple(args, "O", &listObj)) {
		return NULL;
	}
	double det = (PyFloat_AsDouble(PyList_GetItem(PyList_GetItem(listObj, 0), 0)) * PyFloat_AsDouble(PyList_GetItem(PyList_GetItem(listObj, 1), 1))) - 
		         (PyFloat_AsDouble(PyList_GetItem(PyList_GetItem(listObj, 0), 1)) * PyFloat_AsDouble(PyList_GetItem(PyList_GetItem(listObj, 1), 0)));
	return PyFloat_FromDouble(M_PI/sqrt(det));
}

static char square_docs[] = "square( ): calculate square of ellipce\n";
static char sort_docs[] = "sort( ): fast sort a list of integer\n";
static char area_docs[] = "area( ): calculate area of ellipce\n";

static PyMethodDef square_methods[] = {
    {"square", (PyCFunction)square_square, METH_VARARGS, square_docs},
	{"sort", (PyCFunction)square_sort, METH_VARARGS, sort_docs},
	{"area", (PyCFunction)square_area, METH_VARARGS, area_docs},
    {NULL, NULL, 0, NULL}
};

static PyModuleDef square_module = {
	PyModuleDef_HEAD_INIT,
	"square",                       
	"Provides some functions, but faster", 
	0,
	square_methods};

PyMODINIT_FUNC PyInit_square() {
	return PyModule_Create(&square_module);
}