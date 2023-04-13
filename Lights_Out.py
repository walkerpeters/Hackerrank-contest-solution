# Define a function to check if a given cell is within the bounds of the 8x8 grid
def is_valid_cell(row, col):
    return row >= 0 and row < 8 and col >= 0 and col < 8

# Define a function to flip the state of a cell and its neighbors
def flip_cell(grid, row, col):
    if is_valid_cell(row, col):
        # Flip the current cell
        grid[row][col] = 1 - grid[row][col]
        # Flip the neighbor to the right
        if is_valid_cell(row, col+1):
            grid[row][col+1] = 1 - grid[row][col+1]
        # Flip the neighbor below
        if is_valid_cell(row+1, col):
            grid[row+1][col] = 1 - grid[row+1][col]

# Define a function to check if all cells are off
def all_cells_off(grid):
    for row in range(8):
        for col in range(8):
            if grid[row][col] == 1:
                return False
    return True

# Get input from user
current_player = int(input())
grid = []
for i in range(8):
    row = [int(x) for x in input().strip()]
    grid.append(row)

# Determine the opponent player number
opponent_player = 3 - current_player

# Play the game
for turn in range(100):
    # Print current grid
    for row in grid:
        print(''.join(str(x) for x in row))

    # Check if current player has won
    if all_cells_off(grid):
        print(f"Player {current_player} wins!")
        break

    # Get input from current player
    row, col = input().split()
    row, col = int(row), int(col)

    # Check if cell can be flipped
    if grid[row][col] == 0:
        print("Invalid move. Cell is already off.")
        continue

    # Flip the cell and its neighbors
    flip_cell(grid, row, col)

    # Switch to the opponent player
    current_player, opponent_player = opponent_player, current_player

else:
    print("Game is a draw.")
