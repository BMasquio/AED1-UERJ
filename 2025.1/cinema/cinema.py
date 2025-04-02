def solve():
    import sys
    data = input().split(' ')
    n = int(data[0])
    c = int(data[1])
    
    # Read the n x n boolean matrix (0 or 1)
    matrix = []
    for _ in range(n):
        row = list(map(int, input().split(' ')))
        matrix.append(row)
    
    # Build a prefix-sum array where prefix[i][j] = number of zeros in the submatrix (0..i-1, 0..j-1)
    prefix = [[0]*(n+1) for _ in range(n+1)]
    for i in range(n):
        for j in range(n):
            prefix[i+1][j+1] = (prefix[i+1][j]
                                + prefix[i][j+1]
                                - prefix[i][j]
                                + (1 if matrix[i][j] == 0 else 0))
    
    min_area = None    
    # Check every submatrix defined by (r1,c1) to (r2,c2)
    for r1 in range(n):
        for r2 in range(r1, n):
            for c1 in range(n):
                for c2 in range(c1, n):
                    # Count zeros in the submatrix (r1..r2, c1..c2)
                    zeros_count = (prefix[r2+1][c2+1]
                                   - prefix[r2+1][c1]
                                   - prefix[r1][c2+1]
                                   + prefix[r1][c1])
                    
                    if zeros_count >= c:
                        area = (r2 - r1 + 1) * (c2 - c1 + 1)
                        if min_area is None or area < min_area:
                            min_area = area
    
    if min_area is None:
        print(-1)
    else:
        print(min_area)
