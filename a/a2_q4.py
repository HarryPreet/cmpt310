from csp import*
from a2_q1 import *
from a2_q2 import *
import time 

def run_q4():

     for t in range(5):

        graphs = [rand_graph(10, 0.1), rand_graph(100, 0.2), rand_graph(100, 0.3), rand_graph(100, 0.4), rand_graph(100, 0.5)]
        print("Random Batch: ",t+1)
        for u in range(5):
           
            start_time= time.time()
            for n in range(100):
                 domain={i:[] for i in range(n+1)}
                 for j in range(len(domain)):
                     for k in range(len(domain)):
                         domain[k].append(j)
                 
                 p=MapColoringCSP(domain, graphs[u])
                 b= min_conflicts(p)

                 if b==None:
                    continue
                 else:
                    break 

            elapsed_time=time.time()-start_time
            print('\n',u,'.')
           
            print("Elapsed time(in seconds) : ", elapsed_time)       
            print("Number of assigned variables: ",p.nassigns)
            print("Number of unassigned variables: ", p.nuassigns)
            print("Number of teams: " ,len(set(b.values())))
            print("Number of times restore functions in csp is called: ", p.icount)
          
            

   
run_q4()
