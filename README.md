# Input

```
const char data[] = {
    1, 0, 0, 20, // square [figure_id, x, y, size]
    2, 10, 10, 20, 30, // rectangle [figure_id, x, y, size_x, size_y]
    3, 6, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, // polygon [figure_id, vertex_count, x1, y1, x2, y2, x3, y3, ..., x_vertex_count, y_vertex_count]
    4, -10, -10, 15 // circle [figure_id, x, y, radius]
};
```



# Assumptions:
1. Input is always correct
2. Cumulative area is sum of areas of each figures. Overlaps are ignored.

# ToDo:
- [ ] Design functionality for reading input.
- [ ] Mock figure classes in CumulativeAreaCalc tests.
- [ ] Add UT for figure classes.
- [ ] Move CumulativeAreaCalc to separate file.
