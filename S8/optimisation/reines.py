def solve_4_queens():
    """
    Résout le problème des 4 reines sur un échiquier 4x4.
    Retourne une liste de positions [ligne, colonne] pour chaque reine.
    """
    solutions = []
    
    def is_safe(board, row, col):
        # Vérifier la colonne
        for i in range(row):
            if board[i] == col:
                return False
        
        # Vérifier la diagonale gauche
        for i in range(row):
            if abs(board[i] - col) == abs(i - row):
                return False
        
        return True
    
    def backtrack(board, row):
        if row == 4:
            solutions.append(board[:])
            return
        
        for col in range(4):
            if is_safe(board, row, col):
                board[row] = col
                backtrack(board, row + 1)
                board[row] = -1
    
    board = [-1] * 4
    backtrack(board, 0)
    return solutions

# Afficher les solutions
if __name__ == "__main__":
    solutions = solve_4_queens()
    for i, sol in enumerate(solutions, 1):
        print(f"Solution {i}: {sol}")