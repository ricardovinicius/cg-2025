//
// Created by vinia on 4/13/2025.
//

#ifndef BRESENHAM_H
#define BRESENHAM_H

/**
 * @brief Draws a line using Bresenham's line algorithm.
 *
 * This function calculates and draws a straight line from point (x0, y0) to point (x1, y1)
 * using the Bresenham algorithm, which is efficient for raster displays.
 *
 * @param x0 The x-coordinate of the starting point.
 * @param y0 The y-coordinate of the starting point.
 * @param x1 The x-coordinate of the ending point.
 * @param y1 The y-coordinate of the ending point.
 */
void bresenham_line(int x0, int y0, int x1, int y1);

/**
 * @brief Draws an arc using Bresenham's circle algorithm.
 *
 * This function draws an arc of a circle centered at (xc, yc) with radius r,
 * starting from `start_angle` to `end_angle` (in degrees). It uses a modified
 * version of Bresenham’s algorithm adapted for partial circles that uses
 * atan2() function to calculate the angle of each rasterized point of first
 * octant.
 *
 * @param xc The x-coordinate of the center of the circle.
 * @param yc The y-coordinate of the center of the circle.
 * @param r The radius of the circle.
 * @param start_angle The starting angle of the arc, in degrees.
 * @param end_angle The ending angle of the arc, in degrees.
 */
void bresenham_arc(int xc, int yc, int r, int start_angle, int end_angle);


#endif //BRESENHAM_H
