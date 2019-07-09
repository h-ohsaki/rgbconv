/* 
 Convert pixel format from BGRA to RGBA.
 Copyright (c) 2019, Hiroyuki Ohsaki.
 All rights reserved.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

// https://tutorialedge.net/python/python-c-extensions-tutorial/

#include <Python.h>

// convert BGRA format to RGBA format
static PyObject *
bgra2rgba (PyObject * self, PyObject * args)
{
  unsigned char *buf, tmp;
  int size;

  // parse the byte-like object and its length
  if (!PyArg_ParseTuple (args, "y#", &buf, &size))
    return NULL;
  // swap all blue and green pixels
  for (int i = 0; i < size; i += 4)
    {
      tmp = buf[i];
      buf[i] = buf[i + 2];
      buf[i + 2] = tmp;
    }
  return Py_None;
}

static PyMethodDef myMethods[] = {
  {"bgra2rgba", bgra2rgba, METH_VARARGS,
   "Convert BGRA format to RGBA format"},
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef rgbconv = {
  PyModuleDef_HEAD_INIT,
  "rgbconv",
  "functions for RGB format conversion",
  -1,
  myMethods
};

PyMODINIT_FUNC
PyInit_rgbconv (void)
{
  return PyModule_Create (&rgbconv);
}
