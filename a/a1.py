from search import *
import random
import time

def best_first_graph_search(problem, f):

    #Modulated the function a bit to calculate total length of solution and total nodes removed from frontier
    
    """Search the nodes with the lowest f scores first.
    You specify the function f(node) that you want to minimize; for example,
    if f is a heuristic estimate to the goal, then we have greedy best
    first search; if f is node.depth then we have breadth-first search.
    There is a subtlety: the line "f = memoize(f, 'f')" means that the f
    values will be cached on the nodes as they are computed. So after doing
    a best first search you can examine the f values of the path returned."""
    length=0
    f = memoize(f, 'f')
    node = Node(problem.initial)
    frontier = PriorityQueue('min', f)
    frontier.append(node)
    explored = set()
    count_node =0
    while frontier:
        node = frontier.pop()
        length= length+f(node)
        count_node=count_node+1
        if problem.goal_test(node.state):
            print("Total Nodes Removed: ", count_node)
            print("Total Length: ", length)
            return node
        explored.add(node.state)
        for child in node.expand(problem):
            
            if child.state not in explored and child not in frontier:
                frontier.append(child)
            elif child in frontier:
                if f(child) < frontier[child]:
                    del frontier[child]
                    frontier.append(child)
    return None

def make_rand_8puzzle():
    #Makes a random 8 puzzle using sample function from random module
    #Keeps on creating a new random puzzle until it makes a solvable puzzle
    #Returns object of 8Puzzle
    
    puzzle_tuple = tuple(random.sample(range(0,9),9))
    puzzle = EightPuzzle(puzzle_tuple)
    while((puzzle.check_solvability(puzzle.initial))==False):
        puzzle_tuple = tuple(random.sample(range(0,9),9))
        puzzle.initial=puzzle_tuple

    return puzzle

def display(state):
    #Displays a tuple in the format of an 8 puzzle, displays 0 as a *
    
    i=0
    while(i<9):
        
        for j in range(3):
            if(state[i+j]==0):
                print( "*",end='')
            else:
                print(state[i+j],end='')
        print('\n',end='')
        i=i+3

def manhattan(node):
        #Calculates the manhattan distance using list arithmetic, uses some of the code from aima-python repository
        
        state= node.state
        index_goal = {0:[2,2], 1:[0,0], 2:[0,1], 3:[0,2], 4:[1,0], 5:[1,1], 6:[1,2], 7:[2,0], 8:[2,1]}
        index_state = {}
        mhd_state= {}
        index = [[0,0], [0,1], [0,2], [1,0], [1,1], [1,2], [2,0], [2,1], [2,2]]
        
        
        for i in range(len(state)):
            index_state[state[i]] = index[i]
        
        mhd = 0
        for i in range(1,9):
           mhd_state[i]= [ abs(a-b) for a,b in zip(index_state[i],index_goal[i])]
           

        for j in range(1,9):
            for k in range(2):
                mhd = abs(mhd_state[j][k]) + mhd 
   

        
        return mhd
    
def maxh8(node):
    #Retusn max of manhattan and misplaced tile heuristic value
    a= EightPuzzle(node.state)
    return max(manhattan(node), a.h(node))

def maxhy(node):
    #Retusn max of manhattan and misplaced tile heuristic value
    a= YPuzzle(node.state)
    return max(manhattan(node), a.h(node))

class YPuzzle(Problem):

       #The Problem of sliding tiles into y shaped 8 puzzle
       #1 2
       #345
       #678
       # 0
       #Most of the code is copied from the 8puzzle class in search.py
       
 
    def __init__(self, initial, goal=(1, 2, 3, 4, 5, 6, 7, 8, 0)):
        """ Define goal state and initialize a problem """

        self.goal = goal
        Problem.__init__(self, initial, goal)
    
    def find_blank_square(self, state):
        """Return the index of the blank square in a given state"""

        return state.index(0)
    
    def actions(self, state):
        """ Return the actions that can be executed in the given state.
        The result would be a list, since there are only four possible actions
        in any given state of the environment """
        
        possible_actions = ['UP', 'DOWN', 'LEFT', 'RIGHT']
        left=[0,1,2,3,5,8]
        right=[0,1,4,7,8]
        up=[0,1,3]
        down=[5,7,8]
        index_blank_square = self.find_blank_square(state)

        if index_blank_square in left :
            possible_actions.remove('LEFT')
        if index_blank_square in  right:
            possible_actions.remove('RIGHT')
        if index_blank_square in up:
            possible_actions.remove('UP')
        if index_blank_square in down:
            possible_actions.remove('DOWN')

        return possible_actions

    def result(self, state, action):
        """ Given state and action, return a new state that is the result of the action.
        Action is assumed to be a valid action in the state """
       
        #blank is the index of the blank square
        
        blank = self.find_blank_square(state)
        new_state = list(state)
        
        delta = {'UP':{2:0,4:1,5:2,6:3,7:4,8:6},'DOWN':{0:2,1:4,2:5,3:6,4:7,6:8}, 'LEFT':{3:2,4:3,6:5,7:6}, 'RIGHT':{2:3,3:4,5:6,6:7}}
        neighbor = delta[action][blank]
      
        new_state[blank], new_state[neighbor] = new_state[neighbor], new_state[blank]

        return tuple(new_state)

    def goal_test(self, state):
        """ Given a state, return True if state is a goal state or False, otherwise """

        return state == self.goal
    
    def h(self, node):
        """ Return the heuristic value for a given state. Default heuristic function used is 
        h(n) = number of misplaced tiles """
        
        return sum(s != g for (s, g) in zip(node.state, self.goal))

    def change_initial(self,state,act):
        #setter function to change initial state to the action given to the function
        #used in generating random y puzzles
        
        tup= self.result(state,act)
        self.initial=tup        


def make_rand_Ypuzzle():
    #Generates a y puzzle in solved state
    #does 100 random moves onto the puzzle and then returns the modulated puzzle
    #uses class function change_initial
    #Help Taken from TA: Mahmoud
    
    puzzle = YPuzzle((1,2,3,4,5,6,7,8,0))
    
   
    for i in range(100):
        actions = puzzle.actions(puzzle.initial)
        n= random.randint(0,len(actions)-1)
        puzzle.change_initial(puzzle.initial, actions[n])

       
    return puzzle

def displayY(state):
    #displays a given state in the format of a standard y puzzle
    
    i=0
    while(i<7):
        if(i<1):
            if(state[i]==0):
                  print('*',end='')
            else:
                print(state[i],end='')
              

            if(state[i+1]==0):
                  print(' ',end='')
                  print('*',end='')
            else:
                print(' ',end='')
                print(state[i+1],end='')
            i=i+2
        else:
            for j in range(3):
                if(state[i+j]==0):
                  print('*',end='')
                else:
                  print(state[i+j],end='')
            i=i+3
        print('\n',end='')
    
    print(' ',end='')
    if(state[8]==0):
         print('*',end='')
    else:
         print(state[8],end='')
    print(' ')


def Analyse8():

    #function used to call all the different heuristic functions for randomly generated 10 eight puzzles
    #analyses time, nodes removed from frontier and total length of the solution
    #prints the goal state in the format of 8 puzzle
    
    for i in range(10):
        print(i+1,':',"\n\nInitial State : ")
        a= make_rand_8puzzle()
        display(a.initial)

        #Using Default Heuristic
        print("\nUsing Default Heuristic:")
        start_time=time.time()
        g= astar_search(a,a.h)
        elapsed_time=time.time()-start_time
        print("Elapsed time(in seconds) : ", elapsed_time)

        #Using Manhattan Distance
        print("\nUsing Manhattan Heuristic:")
        start_time=time.time()
        g= astar_search(a,manhattan)
        elapsed_time=time.time()-start_time
        print("Elapsed time(in seconds) : ", elapsed_time)

        #Using Max of Manhattan and Default
        print("\nUsing Max(Manhattan, Default:")
        start_time=time.time()
        g= astar_search(a,maxh8)
        elapsed_time=time.time()-start_time
        print("Elapsed time(in seconds) : ", elapsed_time)

        print("\nGoal State : ")
        display(g.state)
        print('\n')


def AnalyseY():

    #function used to call all the different heuristic functions for randomly generated 10 y puzzles
    #analyses time, nodes removed from frontier and total length of the solution
    #prints the goal state in the format of y puzzle
    
    for i in range(10):

        print(i+1,':',"\n\nInitial State : ")
        a= make_rand_Ypuzzle()
        displayY(a.initial)

        #Using Default Heuristic
        print("\nUsing Default Heuristic:")
        start_time=time.time()
        g= astar_search(a,a.h)
        elapsed_time=time.time()-start_time
        print("Elapsed time(in seconds) : ", elapsed_time)

        #Using Manhattan Distance
        print("\nUsing Manhattan Heuristic:")
        start_time=time.time()
        g= astar_search(a,manhattan)
        elapsed_time=time.time()-start_time
        print("Elapsed time(in seconds) : ", elapsed_time)

        #Using Max of Manhattan and Default
        print("\nUsing Max(Manhattan, Default):")
        start_time=time.time()
        g= astar_search(a,maxhy)
        elapsed_time=time.time()-start_time
        print("Elapsed time(in seconds) : ", elapsed_time)
      
        print("\nGoal State : ")
        displayY(g.state)
        print('\n')
            


Analyse8()          
