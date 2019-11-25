import numpy as np
from matplotlib.patches import Polygon
from matplotlib.collections import PatchCollection
import matplotlib.pyplot as plt

all_points_file = open("./all-points.txt", "r")
all_points_x = list()
all_points_y = list()
for line in all_points_file:
    x = float(line.split(" ")[0])
    y = float(line.split(" ")[1].split("\n")[0])
    all_points_x.append(x)
    all_points_y.append(y)

all_points_file.close()

polygon_points_file = open("./polygon-points.txt", "r")
polygon_points = list()
for line in polygon_points_file:
    x = float(line.split(" ")[0])
    y = float(line.split(" ")[1].split("\n")[0])
    polygon_points.append([x, y])

polygon_points_file.close()

fig, ax = plt.subplots()

patches = list()
polygon_points = np.array(polygon_points, np.float32)
polygon = Polygon(polygon_points, False)
patches.append(polygon)

p = PatchCollection(patches, alpha=0.4)
ax.add_collection(p)

plt.scatter(all_points_x, all_points_y)

plt.ylabel('All Points')
plt.savefig("all-points.png")
