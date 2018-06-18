int islandPerimeter(int **grid, int gridRowSize, int gridColSize) {
    int rv = 0;
    int i, j;
    if(grid[0][0]){
        rv+=4;
    }
    for (i = 1; i < gridRowSize; ++i) {
        if (grid[i][0]) {
            rv += 2;
            if(!grid[i-1][0]){
                rv+=2;
            }
        }
    }
    int *row = grid[0];
    for (j = 1; j < gridColSize; ++j) {
        if (row[j]) {
            rv += 2;
            if(!row[j-1]){
                rv+=2;
            }
        }
    }
    for (i = 1; i < gridRowSize; ++i) {
        row = grid[i];
        for (j = 1; j < gridColSize; ++j) {
            if (row[j]) {
                if (!grid[i - 1][j]) {
                    rv += 2;
                }
                if (!row[j - 1]) {
                    rv += 2;
                }
            }
        }
    }
    return rv;
}