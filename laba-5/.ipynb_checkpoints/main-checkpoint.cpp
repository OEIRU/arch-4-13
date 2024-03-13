#include <iostream>
#include <C:\Users\???\AppData\Local\Programs\Python\Python310\include\Python.h>

int main() {
    Py_Initialize();
    PyRun_SimpleString("import matplotlib.pyplot as plt");
    PyRun_SimpleString("import numpy as np");
    PyRun_SimpleString("x = np.arange(-10, 10, 0.01)");
    PyRun_SimpleString("plt.plot(x, x**3 + x**2 + x +1)");
    PyRun_SimpleString("plt.show()");
    Py_Finalize();
}