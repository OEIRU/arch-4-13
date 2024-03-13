from cmath import pi
from scipy import integrate
import numpy as np
import random
from datetime import datetime
import square 

A = [[2, 0], [0, 2]]

func = lambda x: np.sqrt((1 - A[0][0]*np.power(x, 2))/A[1][1])
I, err = integrate.quad(func, -1/np.sqrt(A[0][0]), 1/np.sqrt(A[0][0]))
print(f'python scipy integrate: {2 * I}')
print(f'python area: {pi/np.sqrt(np.linalg.det(A))}')

print(f'square_simpson: {square.square(A)}')
print(f'square_area: {square.area(A)}')

size = 10000000
l = [random.randint(-1000, 1000) for i in range(size)]

start_time = datetime.now()
result1 = sorted(l)
print(f'python sorted: {datetime.now() - start_time}')

start_time = datetime.now()
result2 = square.sort(l, 0, size)
print(f'square sort: {datetime.now() - start_time}')

print(result2)