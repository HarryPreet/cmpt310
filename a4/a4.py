#a4.py

import random
import time
random.seed(time.time())
import math 

def drawBoard(board):
     print('   |   |')
     print(' ' + str(board[1]) + ' | ' + str(board[2]) + ' | ' + str(board[3]))
     print('   |   |')
     print('-----------')
     print('   |   |')
     print(' ' + str(board[4]) + ' | ' + str(board[5]) + ' | ' + str(board[6]))
     print('   |   |')
     print('-----------')
     print('   |   |')
     print(' ' + str(board[7]) + ' | ' + str(board[8]) + ' | ' + str(board[9]))
     print('   |   |')


def checkwin(board,char):

    #row
    for i in range(1,8,3):
        if board[i]==board[i+1]==board[i+2]==char:
            return True
    #column
    for i in range(1,4):
         if board[i]==board[i+3]==board[i+6]==char :
             return True
    #diagnols
    if board[1]==board[5]==board[9] ==char:
        return True

    if board[3]==board[5]==board[7] ==char:
        return True
        
    return False


def checkdraw(board):
    if(len(find_possible_moves(board))==0):
        return True
    return False


def checkloss(board,char,oppo_char):
    if(checkwin(board, oppo_char)):
        return True
    return False

def inputUserMove():
    pos= input()
    if (pos<='9' and pos >='1'):
        return int(pos)
    else:
        print("Enter Valid Move")
        return inputUserMove()

def find_possible_moves(board):
    possible_moves=[]
    for i in range(1,10):
        if (board[i] == '*'):
            possible_moves.append(i)
    return possible_moves

def actmove(board,pos,char):
    board[pos]=char
    

def inputComputerMove(board,user_char,ai_char):
    possible=find_possible_moves(board)
    max_stat=900000
    index=0
    
    
    for i in range(len(possible)):
        wins=0
        draws=0
        loss=0
        
        for j in range(1000):
            tboard=[]
            for k in range(len(board)):
                tboard.append(board[k])
            actmove(tboard,possible[i],ai_char)
            while(True):
                if(checkwin(tboard,ai_char)):
                    wins=wins+400
                    break
                if(checkdraw(tboard)):
                    draws=draws+100
                    break 
                actmove(tboard,random.choice(find_possible_moves(tboard)),user_char)
                if(checkwin(tboard,user_char)):
                    loss=loss+100
                    break
                if(checkdraw(tboard)):
                    draws=draws+1
                    break
                actmove(tboard,random.choice(find_possible_moves(tboard)),ai_char)
        stat=loss-(wins+draws)
        if(stat<(max_stat)):
            max_stat=stat
            index=i

    return possible[index]
    

def validate_move(board,pos):
    possible_moves=find_possible_moves(board)
    if(pos in possible_moves):
        return True
    else:
        return False

def gameplay(board,user_char, ai_char):
     c_pos=inputComputerMove(board,user_char,ai_char)
     board[c_pos]=ai_char
     print("Computer Move: ", c_pos)
     drawBoard(board)
     if (checkwin(board,ai_char)):
         print("Computer Won")
         return False
     if(checkdraw(board)):
         print("Drawn")
         return False
     print('Choose your move: ',end="")
     pos=inputUserMove()
     while(not validate_move(board,pos)):
         print("Invalid Move! Enter Again: ", end="")
         pos=inputUserMove()
     board[pos]=user_char
     print('\n')
     drawBoard(board)
     if (checkwin(board,user_char) and checkloss(board,ai_char,user_char)):
         print("User won")
         return False
     if(checkdraw(board)):
         print("Drawn")
         return False
    
     return True    
    
def play_a_new_game():

    default=["*","1","2","3","4","5","6","7","8","9"]
    print("Guide for moves:")
    drawBoard(default)
    print()
    ans='y'
    while(ans=='y'):
        board = ['*' for i in range(1,11) ]
        drawBoard(board)
        print("Choose your character: 'X' or 'O'- ", end="")
        user_char= input().upper()
        a=True
    
    
        while(a):
            if (user_char=='X'):
                ai_char='O'
                a=False
            elif(user_char=='O'):
                ai_char='X'
                a=False
            else:
                a= True
                print('Enter Valid Char')
                user_char= input().upper()
        flag = True
        while(flag):
            if('*' not in board):
                break
            flag=gameplay(board,user_char,ai_char)
        print('Game Over')
        print('Continue?(y/n): ')
        ans=input()

if __name__ == '__main__':
  play_a_new_game()


