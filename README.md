# NAME

rgbconv - Fast RGB image pixel format conversion module written in C

# DESCRIPTION

This manual page documents **rgbconv** module, a Python module for rapidly
converting image pixel format from BGRA (Blue, Green, Red, and Alpha) to RGBA
(Red, Green, Blue, and Alpha).  

Different aplications/modules use different pixel formats for represenging
pixels in images and photos.  One of the most popular formats are 24-bit RGB
(8 bits each for red, green, and blue) and 32-bit RGBA (8 bits each for red,
green, blue, alpha).  Other formats include 32-bit BGRA (8 bits for blue,
green, red, and alpha) and 32-bit RGBX (8bits for red, gree, blue, and
unused).

**rgbconv** provides *bgra2rgba*, which rapidly converts from the BGRA format
to the RGBA format.  **rgbconv** is implemented in C language for achieving
the almost optimal performance.

# EXAMPLES

```
import rgbconv

img = b'01234567890abcdef'
rgbconv.bgra2rgba(img)
print(img)

```

# WARNING

**rgbconv** directly modifies a byte-like object in Python for the maximal
performance even if the object is immutable, which may cause problems.  Use
**rgbconv** module with caution.

# INSTALLATION

```python
pip3 install rgbconv
```

# AVAILABILITY

The latest version of **rgbconv** module is available at PyPI
(https://pypi.org/project/rgbconv) .

# SEE ALSO

# AUTHOR

Hiroyuki Ohsaki <ohsaki[atmark]lsnl.jp>
