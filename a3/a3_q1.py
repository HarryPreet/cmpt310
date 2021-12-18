import math 
import time
def make_queen_sat(N):
	size = N*N
	f= open("graphs2.txt","w+")
	
	variable_count = size
	clause_count =0

	#row constraints
	row_board= {i:[j for j in range(i,N+i)] for i in range(1,size,N)}
	
	for i in row_board:
		s= " ".join(str(x) for x in row_board[i])+ ' 0'+ '\n'
		clause_count=clause_count+1
		f.write(s)
		for j in range(N):
			for k in range(j+1,N):
				clause_count=clause_count+1
				clause = str(-row_board[i][j])+str(-row_board[i][k])+' 0'+'\n'
				f.write(clause)
	
	#column constraints

	column_board= {i:[j for j in range(i,size+1,N)] for i in range(1,N+1)}
	
	for i in column_board:
		s= " ".join(str(x) for x in column_board[i])+' 0' +'\n'
		clause_count=clause_count+1
		f.write(s)
		for j in range(N):
			for k in range(j+1,N):
				clause_count=clause_count+1
				clause = str(-column_board[i][j])+str(-column_board[i][k])+' 0'+'\n'
				f.write(clause)


	#diagnol constraints

	diagnol_board = {i:[]   for i in range(0,N)}
	
	for i,j in zip(diagnol_board, row_board):
		diagnol_board[i]= row_board[j]

	fdiag = [[] for _ in range(N+ N- 1)]
	bdiag = [[] for _ in range(len(fdiag))]
	min_bdiag = -N+ 1

	for r in range(N):
		for c in range(N):
			fdiag[r+c].append(diagnol_board[r][c])
			bdiag[r-c-min_bdiag].append(diagnol_board[r][c])

	for i in range(1,len(fdiag)-1):
		for j in range(len(fdiag[i])):
			for k in range(j+1, len(fdiag[i])):
				clause_count=clause_count+1
				clause= str(-fdiag[i][j])+str(-fdiag[i][k])+' 0'+'\n'
				f.write(clause)
			 
	for i in range(1,len(bdiag)-1):
		for j in range(len(bdiag[i])):
			for k in range(j+1, len(bdiag[i])):
				clause_count=clause_count+1
				clause= str(-bdiag[i][j])+str(-bdiag[i][k])+' 0'+'\n'
				f.write(clause)
	f.close()
	f=open("graphs2.txt","r")
	oldlines = f.read()
	f.close()


	st= "c N = " +str(N)+ " queens problem " +'\n'
	header= "p cnf "+ str(size) + " "+str(clause_count)+'\n'
	newlines= st + header+oldlines
	
	f=open("graphs2.txt", "w+")
	f.write(newlines)
	f.close()




def draw_queen_sat_sol(sol):
	sat_sol =sol.split()
	sat_sol=list(map(int,sat_sol))
	n= len(sat_sol)
	sq= int(math.sqrt(n))
	
	if(n>40):
		print("Too Big")
	else:
		for i in range(n):
			if((i%sq)==0):
				print('')
			if(sat_sol[i]<0):
				print(' *',end='')
			elif(sat_sol[i]==0):
				pass
			else:
			    print(' Q',end='')
		print('\n')
			
def draw():
	
	f = open("out","r+")
	lst= f.readlines()
	f.close()
	if(len(lst)==1):
		print("No Solution")
		return 
	else:
		sol= lst[1]
		draw_queen_sat_sol(sol)




import os





def experiment():
	n=2
	while(True):
		
		make_queen_sat(n)
		current_time = time.time()
		os.system('minisat graphs2.txt out')
		elapsed_time= time.time()- current_time
		if(elapsed_time>10):
			print(n)
			break
		n=n+1
		draw()


experiment()
