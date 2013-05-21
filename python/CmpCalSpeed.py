# -*- coding: cp936 -*-
# 比较numpy.math 和Python标准库的math.sin的计算速度

import time
import math
import numpy as np

x = [i * 0.001 for i in xrange(1000000)]
start = time.clock()
for i, t in enumerate(x):
    x[i] = math.sin(t) # math.sin 计算单个数比较快
print "math.sin: ", time.clock() - start

x = [i * 0.001 for i in xrange(1000000)]
x = np.array(x)
start = time.clock()
np.sin(x, x) # numpy.sin 计算两个数比较快
print "numpy.sin: ", time.clock() - start
