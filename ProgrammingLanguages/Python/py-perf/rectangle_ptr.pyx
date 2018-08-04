# disutils: language = c++

from Rectangle cimport Rectangle as CRectangle

cdef class Rectangle:
  cdef CRectangle * c_rect;

  def __cinit__(self, int x0, int y0, int x1, int y1):
    self.c_rect = new CRectangle(x0, y0, x1, y1)

  def __dealloc__(self):
    del self.c_rect

  def area(self):
    return self.c_rect.getArea()

  def size(self):
    cdef int width, height
    self.c_rect.getSize(&width, &height)
    return width, height

  # access via attribute

  # x0
  @property
  def x0(self):
    return self.c_rect.x0
  @x0.setter
  def x0(self, int val):
    self.c_rect.x0 = val

  # y0
  @property
  def y0(self):
    return self.c_rect.y0
  @y0.setter
  def y0(self, int val):
    self.c_rect.y0 = val

  # x1
  @property
  def x1(self):
    return self.c_rect.x1
  @x1.setter
  def x1(self, int val):
    self.c_rect.x1 = val

  # y1
  @property
  def y1(self):
    return self.c_rect.y1
  @y1.setter
  def y1(self, int val):
    self.c_rect.y1 = val




