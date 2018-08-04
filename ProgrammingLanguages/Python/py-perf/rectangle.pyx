# disutils: language = c++

from Rectangle cimport Rectangle as CRectangle

cdef class Rectangle:
  cdef CRectangle c_rect

  def __cinit__(self, int x0, int y0, int x1, int y1):
    self.c_rect = CRectangle(x0, y0, x1, y1)

  def get_area(self):
    return self.c_rect.getArea()

  def get_size(self):
    cdef int width, height
    self.c_rect.getSize(&width, &height)
    return width, height

  def move(self, int dx, int dy):
    self.c_rect.move(dx, dy)

