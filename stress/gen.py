import random
from random import randint as rand

n = 2

a = []
b = []

for i in range(2):
    a.append(rand(1, n))
    a.append(rand(1, n))

for i in range(2):
    b.append(rand(1, n))
    b.append(rand(1, n))


with open('input.in', 'w') as file:
    file.write("2 2 1\n")
    file.write(str(a[0]) + ' ' + str(a[1]) + '\n' + str(a[2]) + ' ' + str(a[3]) + '\n')
    file.write(str(b[0]) + ' ' + str(b[1]) + '\n' + str(b[2]) + ' ' + str(b[3]) + '\n')