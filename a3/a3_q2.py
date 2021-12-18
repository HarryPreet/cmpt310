import random 

def rand_graph(n, p):
     g={i:[] for i in range(1,n+1)}
     
     for i in range(1,n+1):
         for j in range(i,n+1):
            if i!=j:
                r = random.uniform(0,1)
                if r<=p:
                    g[i].append(j)
                    g[j].append(i)
    
     return g


def check_teams(graph, csp_sol):
    for i in range(len(csp_sol)):
        for j in range(len(graph[i])):
            if(csp_sol[i]==graph[i][j]):
                return False
    return True


def make_ice_breaker_Sat(graph,k):
	size = len(graph)*k
	f= open("graphs3.txt","w+")
	
	variable_count = size
	clause_count =0

	#row constraints
	l=len(graph)
	board= {i:{j:[(l*(i-1))+j] for j in range(1,len(graph)+1) }for i in range(1,k+1)}
	
	
	for i in range(1,l+1):
		for j in range(len(graph[i])):
			for u in range(1,k+1):
				clause_count=clause_count+1
				s=str(-board[u][i][0])+str(-board[u][graph[i][j]][0])+ ' 0\n'
				f.write(s)
	

	#column constraints
	
	for i in range(1,k+1):
		for j in range(1,len(graph)+1):
			for u in range(i+1,k):
				clause_count=clause_count+1
				s=str(-board[i][j][0])+str(-board[u][j][0])+' 0\n'
				f.write(s)

	
	for i in range(1,k+1):
		s=str(board[i][1][0])
		for j in range(1,len(graph)):
			s= s + ' ' +str(board[i][j+1][0])

		s=s+ ' 0\n'
		clause_count=clause_count+1
		f.write(s)

	for j in range(1,len(graph)+1):
		s=str(board[1][j][0])
		for i in range(1,k):
			s= s + ' ' +str(board[i+1][j][0])

		s=s+ ' 0\n'
		clause_count=clause_count+1
		f.write(s)

	f.close()
	f=open("graphs3.txt","r")
	oldlines = f.read()
	f.close()


	st= "c N = " + " queens problem " +'\n'
	header= "p cnf "+ str(size) + " "+str(clause_count)+'\n'
	newlines= st + header+oldlines
	
	f=open("graphs3.txt", "w+")
	f.write(newlines)
	f.close()

import os 

def find_min_teams(graph):
	
	n=0
	l=len(graph)
	

	while(l!=0):
		
		make_ice_breaker_Sat(graph,l)
		os.system('minisat graphs3.txt output')
		o=open("output","r+")
		lines=o.readlines()
		print(lines)
		if(lines[0]=="UNSAT\n"):
			return n
		else:
			
			teams=lines[1].split()
			for i in range(len(teams)):
				if (int(teams[i])>0):
					n=n+1
		l=l-1
		o.close()
	

import time

def experiment():
	
	for i in range(1,10):
		for j in range(1,11):
			g= rand_graph(10,i/10)
			current_time=time.time()
			n=find_min_teams(g)
			

experiment()




