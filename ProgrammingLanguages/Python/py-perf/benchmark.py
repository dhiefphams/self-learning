import timeit

cypy = timeit.timeit('starter.test(1000000)', setup='import starter', number=100)
cpy = timeit.timeit('starter.csum(1000000)', setup='import starter', number=100)
cc = timeit.timeit('sum.sum(1000000)', setup="import ctypes; sum=ctypes.CDLL('sum.so')", number=100)

print(cypy, cpy, cc)

