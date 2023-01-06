import numpy

NDIM = 3.0 # number of dimensions

# read points into array
a = numpy.fromfile('gaaa.txt', sep=' ')
a.shape = a.size / NDIM, NDIM

point = numpy.random.uniform(0, 100, NDIM) # choose random point
print ('point:', point)
d = ((a-point)**2).sum(axis=1)  # compute distances
ndx = d.argsort() # indirect sort 

# print 10 nearest points to the chosen one
import pprint
pprint.pprint(zip(a[ndx[:10]], d[ndx[:10]]))