# Tips

## In Place
Consider storing/reading individual bits for information

Example with Game of Life, where
- 11 = alive -> alive
- 10 = alive -> dead
- 01 = dead -> alive
- 00 = dead -> dead
```python3
    for x in range(len(board)):
        for y in range(len(board[0])):
            count=self.num_neighbors(board,x,y)
            if( ((count==2 or count==3) and board[x][y] ) or
                ((count==3) and not board[x][y] )):
                board[x][y]|=2;

    for x in range(len(board)):
        for y in range(len(board[0])):
            board[x][y] >>= 1;
```
