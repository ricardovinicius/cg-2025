from dataclasses import dataclass


@dataclass
class Point:
    x: float
    y: float


def line_equation(start_point: Point, end_point: Point, current_x: float):
    slope = (end_point.y - start_point.y) / (end_point.x - start_point.x)
    y = start_point.y + slope * (current_x - start_point.x)

    return y


def rasterize(start_point: Point, end_point: Point):
    for x in range(int(start_point.x), int(end_point.x) + 1):
        y = line_equation(start_point, end_point, x)

        print([x, round(y)])


rasterize(Point(1, 1), Point(4, 3))
