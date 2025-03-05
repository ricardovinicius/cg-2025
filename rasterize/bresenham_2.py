"""
Simple bresenham line implementation

Example:
Rasterize the line between (1, 1) and (8, 5)

Result:
(1, 1)
(2, 2)
(3, 2)
(4, 3)
(5, 3)
(6, 4)
(7, 4)
(8, 5)
"""

import tkinter as tk

from dataclasses import dataclass


@dataclass
class Point:
    x: float
    y: float


def calc_d_start(start_point: Point, end_point: Point):
    return (end_point.y - start_point.y) * 2 - (end_point.x - start_point.y)


def bresenham(old_d: int, start_point: Point, end_point: Point):
    if old_d > 0:
        return 2 * ((end_point.y - start_point.y) - (end_point.x - start_point.x))

    if old_d < 0:
        return 2 * (end_point.y - start_point.y)

    if old_d == 0:
        return 1


def rasterize(start_point: Point, end_point: Point) -> list[tuple[int, int]]:
    d = calc_d_start(start_point, end_point)

    current_point = Point(start_point.x, start_point.y)

    dots = []
    dots.append((current_point.x, current_point.y))

    print((current_point.x, current_point.y))

    for _ in range(int(start_point.x) + 1, int(end_point.x) + 1):
        if d > 0:
            current_point.x += 1
            current_point.y += 1

        if d < 0:
            current_point.x += 1

        if d == 0:
            current_point.x += 1
            current_point.y += 1

        print((current_point.x, current_point.y))
        dots.append((current_point.x, current_point.y))
        d += bresenham(d, start_point, end_point)

    return dots


def print_dot(canvas: tk.Canvas, dot: Point):
    canvas.create_rectangle(
        dot[0] * CANVAS_MULTIPLIER,
        CANVAS_HEIGHT - (dot[1] * CANVAS_MULTIPLIER),
        (dot[0] + 1) * CANVAS_MULTIPLIER,
        CANVAS_HEIGHT - (dot[1] + 1) * CANVAS_MULTIPLIER,
        fill="white",
        outline="white")


root = tk.Tk()
root.title("Simple bresenham application")

CANVAS_MULTIPLIER = 1
CANVAS_HEIGHT = 1000 * CANVAS_MULTIPLIER
CANVAS_WIDTH = 1000 * CANVAS_MULTIPLIER


canvas = tk.Canvas(root, width=CANVAS_WIDTH,
                   height=CANVAS_HEIGHT, bg="black")
canvas.pack()

dots = rasterize(Point(1, 1), Point(800, 500))

for dot in dots:
    print_dot(canvas, dot)

root.mainloop()
