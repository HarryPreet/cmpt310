
def check_teams(graph, csp_sol):
    for i in range(len(csp_sol)):
        for j in range(len(graph[i])):
            if(csp_sol[i]==graph[i][j]):
                return False
    return True


    
              


    
