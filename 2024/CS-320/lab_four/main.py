def longest_path(ribbon):
    """
    Main function to find the longest path of increasing values in a looped ribbon matrix.
    Returns a tuple of coordinates representing the longest path, or None if input is invalid.
    """
    # input validation
    if not ribbon or len(ribbon) == 0 or len(ribbon[0]) == 0:
        return None
    # getting the size of the matrix as m, n
    m, n = len(ribbon), len(ribbon[0])
    # initilize the tuple that will store the collection of points that represent a 'path'
    longest_path_result = ()

    # cache to ignore paths that were already 'walked'
    cache = {}

    # for every element in the matrix we will try to find the longest path
    for i in range(m):
        for j in range(n):
            path = find_longest_increasing_path(ribbon, i, j, cache, n)
            if len(path) > len(longest_path_result):
                longest_path_result = path

    if len(longest_path_result) > 1:
        return tuple(longest_path_result)
    else:
        return ()


def find_longest_increasing_path(ribbon, x, y, cache, n):
    """
    Finds the longest increasing path starting from the given (x, y) position in the ribbon.
    This will store computed paths to optimize for searching.
    """
    # if this space is already stored then we can start here and go again
    if (x, y) in cache:
        return cache[(x, y)]
    
    # start the path with the given X and Y
    current_value = ribbon[x][y]
    longest_path = [(x, y)]

    # 4 cardinal directions and last two are wrap around movements
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0), (0, n - 1), (0, 1 - n)]

    # checking all directions including ribbon wrap
    for dx, dy in directions:
        nx, ny = x + dx, (y + dy) % n
        if 0 <= nx < len(ribbon) and 0 <= ny < n and ribbon[nx][ny] > current_value:
            path = find_longest_increasing_path(ribbon, nx, ny, cache, n)
            if len(path) > len(longest_path) - 1:
                longest_path = [(x, y)] + path

    # cache the results so we don't overlap another found path
    cache[(x, y)] = longest_path
    return longest_path


# Example usage
if __name__ == "__main__":
    # A ribbon is a 2D Matrix where the rightmost column is adjacent to the leftmost column.
    ribbon = (
        (1, 2, 3),
        (6, 5, 4),
        (7, 8, 9),
        (12, 11, 10)
    )
    simple_ribbon = (
        (0, 1, 2),
        (5, 4, 3),
        (6, 7, 8),
    )
    simple_ribbon_solution = ((0, 0), (0, 1), (0, 2), (1, 2), (1, 1), (1, 0), (2, 0), (2, 1), (2, 2))
    print(longest_path(simple_ribbon) == simple_ribbon_solution)
    