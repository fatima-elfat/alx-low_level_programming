#!/usr/bin/python3
"""module for the island perimeter."""


def island_perimeter(grid):
    """
    returns the perimeter of the island described in grid.
    Arguments:
        grid (list): a list.
    Returns: the perimeter of the island described in grid.
    """
    r = 0
    a = len(grid) - 1
    b = len(grid[0]) - 1
    for i in range(a + 1):
        for j in range(b + 1):
            if grid[i][j] == 1:
                if i == 0 or grid[i - 1][j] == 0:
                    r += 1
                if j == 0 or grid[i][j - 1] == 0:
                    r += 1
                if i == a or grid[i + 1][j] == 0:
                    r += 1
                if j == b or grid[i][j + 1] == 0:
                    r += 1
    return r
