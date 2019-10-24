dfs_runner: node.o graph.o dfs_runner.o
	g++ node.o graph.o dfs_runner.o -o dfs_runner

bfs_runner: node.o graph.o bfs_runner.o
	g++ node.o graph.o bfs_runner.o -o bfs_runner

lds_runner: node.o graph.o lds_runner.o
	g++ node.o graph.o lds_runner.o -o lds_runner 

ids_runner: node.o graph.o ids_runner.o
	g++ node.o graph.o ids_runner.o -o ids_runner 

%.o: %.cpp
	g++ -c -o $@ $<