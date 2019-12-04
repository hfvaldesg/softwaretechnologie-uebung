import numpy as np
from matplotlib.patches import Polygon, Rectangle
from matplotlib.collections import PatchCollection
import matplotlib.pyplot as plt
import math


def process_points(filename):
    points_file = open(filename, "r")
    points = list()
    for line in points_file:
        x = float(line.split(" ")[0])
        y = float(line.split(" ")[1].split("\n")[0])
        points.append([x, y])
    points_file.close()
    return points


if __name__ == "__main__":
    # Process "all-points.txt" file
    all_points_file = open("./all-points.txt", "r")
    all_points_x = list()
    all_points_y = list()
    for line in all_points_file:
        x = float(line.split(" ")[0])
        y = float(line.split(" ")[1].split("\n")[0])
        all_points_x.append(x)
        all_points_y.append(y)

    all_points_file.close()

    # Process "polygon-points.txt" file
    polygon_points = process_points("./polygon-points.txt")

    # Process "rectangle-points.txt"
    #rectangle_points_file = open("./rectangle-points.txt", "r")
    rectangle_points = process_points("./rectangle-points.txt")

    # For better plotting sort the points (or the minimal rectangle is not going to close)
    pp = rectangle_points
    cent=(sum([p[0] for p in pp])/len(pp),sum([p[1] for p in pp])/len(pp))
    pp.sort(key=lambda p: math.atan2(p[1]-cent[1],p[0]-cent[0]))

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

    # Add all the points
    plt.scatter(all_points_x, all_points_y)

    # Plot the graph
    plt.ylabel('All Points')
    plt.gca().set_aspect('equal', adjustable='box')
    plt.savefig("all-points.png")
