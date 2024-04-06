''' This is the main logic for a Tic-tac-toe game.
It is not optimised for a quality game it simply
generates random moves and checks the results of
a move for a winning line. Exposed functions are:
newGame()
saveGame()
restoreGame()
userMove()
computerMove()
'''

import os, random
import oxo_data

class Game:
    def __init__(self) -> None:
        self.list = self.newGame()

    def newGame(self):
        ' return new empty game'
        return list(" " * 9)

    def saveGame(self):
        ' save game to disk '
        oxo_data.saveGame(self.list)
        
    def restoreGame(self, list):
        ''' restore previously saved game.
        If game not restored successfully return new game'''
        try:
            list = oxo_data.restoreGame()
            if len(list) == 9:
                return list
            else: return self.newGame()
        except IOError:
            return self.newGame()
        
    def _generateMove(self):
        ''' generate a random cell from thiose available.
            If all cells are used return -1'''
        options = [i for i in range(len(self.list)) if self.list[i] == " "]
        if options:
            return random.choice(options)
        else: return -1
        
    def _isWinningMove(self):
        wins = ((0,1,2), (3,4,5), (6,7,8),
                (0,3,6), (1,4,7), (2,5,8),
                (0,4,8), (2,4,6))

        for a,b,c in wins:
            chars = self.list[a] + self.list[b] + self.list[c]
            if chars == 'XXX' or chars == 'OOO':
                return True
        return False

    def userMove(self, cell):
        if self.list[cell] != ' ':
            raise ValueError('Invalid cell')
        else:
            self.list[cell] = 'X'
        if self._isWinningMove():
            return 'X'
        else:
            return ""

    def computerMove(self):
        cell = self._generateMove()
        if cell == -1:
            return 'D'
        self.list[cell] = 'O'
        if self._isWinningMove():
            return 'O'
        else:
            return ""

def test():
    result = ""
    game = Game()
    while not result:
        threeByThree = [[game.list[x + y * 3] for x in range(3)] for y in range(3)]
        for row in threeByThree:
            print(row)
        print('\n')
        try:
            result = game.userMove(game._generateMove())
        except ValueError:
            print("Oops, that shouldn't happen")
        if not result:
            result = game.computerMove()
                
        if not result: continue
        elif result == 'D':
            print("Its a draw")
        else:
            print("Winner is:", result)
            threeByThree = [[game.list[x + y * 3] for x in range(3)] for y in range(3)]
            for row in threeByThree:
                print(row)

if __name__ == "__main__":
    test()

            
