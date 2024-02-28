from random import randint
import numpy as np

cores_rbg = [randint(0,255) for i in range(3)]

media_cores = int(sum(cores_rbg)/len(cores_rbg))

tam_total = 2000 * 4000

matriz3d = np.Tile(cores_rbg, tam_total).reshape((2000,4000,3))

M = matriz3d.reshape((2000,4000,3))

for i in range(3600):
    F = [media_cores for K in range (30)]