

def valid(vertex):
	global n_rows, n_cols,graph;
	row=vertex[0]
	col=vertex[1]
	if(row<0 or col<0):
		return False;
	elif(row>=n_rows or col>=n_cols):
		return False;
	else:
		return (graph[row][col]!='*')
def hash(vertex):
	return str(vertex[0])+":"+str(vertex[1])
def bfs():
	global n_rows, n_cols,graph;
	start=[0,0]
	for r in range (0, n_rows):
		for c in range (0, n_cols):
			if(graph[r][c]=='V'):
				start=[r,c];
				break;

	visited=set();
	level=[];
	turns=-1;
	level.append(start);
	visited.add(hash(start));
	while len(level)!=0:
		next_level=[]
		for vertex in level:
			if(valid(vertex) and graph[vertex[0]][vertex[1]]=='H'):
				return turns;
			directions=[ [0,1], [0,-1], [1,0], [-1,0]];
			for d in directions:
				new_vertex=[vertex[0]+d[0],vertex[1]+d[1]]
				while(valid(new_vertex) and hash(new_vertex) not in visited):
					next_level.append(new_vertex)
					visited.add(hash(new_vertex))
					new_vertex=[new_vertex[0]+d[0],new_vertex[1]+d[1]]
		level=next_level;
		turns+=1;
	return -1


[n_rows,n_cols]=[5,4]
graph=[]
graph.append(list("V..*"))
graph.append(list("***H"))
graph.append(list("...."))
graph.append(list(".***"))
graph.append(list("...*"))
print(graph)
print(bfs())