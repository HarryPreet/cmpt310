from csp import*


def rand_graph(n, p):
     g={i:[] for i in range(n)}
     
     for i in range(n):
         for j in range(i,n):
            if i!=j:
                r = random.uniform(0,1)
                if r<=p:
                    g[i].append(j)
                    g[j].append(i)
    
     print(g)
    
rand_graph(10,0.5)







    
