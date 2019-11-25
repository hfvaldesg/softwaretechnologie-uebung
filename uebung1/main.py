import numpy as np
from matplotlib.patches import Polygon, Rectangle
from matplotlib.collections import PatchCollection
import matplotlib.pyplot as plt
import math

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

rectangle_points_file = open("./rectangle-points.txt", "r")
rectangle_points = list()
for line in rectangle_points_file:
    x = float(line.split(" ")[0])
    y = float(line.split(" ")[1].split("\n")[0])
    rectangle_points.append([x, y])

# For better plotting sort the points
pp = rectangle_points
cent=(sum([p[0] for p in pp])/len(pp),sum([p[1] for p in pp])/len(pp))
pp.sort(key=lambda p: math.atan2(p[1]-cent[1],p[0]-cent[0]))

rectangle_points_file.close()

fig, ax = plt.subplots()

patches = list()

# Add the Convex Hull points
polygon_points = np.array(polygon_points, np.float32)
polygon = Polygon(polygon_points, False)
patches.append(polygon)

# Add the minimal area rectangle points
rectangle_points = np.array(rectangle_points, np.float32)
rectangle = Polygon(rectangle_points, False)
patches.append(rectangle)

p = PatchCollection(patches, alpha=0.4)
ax.add_collection(p)

plt.scatter(all_points_x, all_points_y)
# plt.scatter([x for x,y in rectangle_points], [y for x,y in rectangle_points])

plt.ylabel('All Points')
plt.savefig("all-points.png")
