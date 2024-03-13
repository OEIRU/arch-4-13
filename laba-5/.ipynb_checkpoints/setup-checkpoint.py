from distutils.core import setup, Extension

setup(name='square', version='1.5',\
      ext_modules=[Extension('square', ['square.cpp'])])