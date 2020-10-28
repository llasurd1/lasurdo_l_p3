all: submission

p1: submission.cpp
	g++ -g submission.cpp -o submission
	
	p2:
	./submission smallInput.txt smallOutputGreedy2.txt 1
	p3:
	./submission smallInput.txt smallOutputBacktracking.txt 2
	p4:
	./submission input.txt outputGreedy2.txt 1
	p5:
	./submission input.txt outputBacktracking.txt 2
	p6:
	./submission mediumInput.txt mediumOutputGreedy2.txt 1
	p7:
	./submission mediumInput.txt mediumOutputBacktracking.txt 2
	p8
	./submission badGreedyInput.txt outputbadGreedy1.txt 0
	p9
	./submission badGreedyInput.txt outputbadGreedy2.txt 1
	p10
	./submission badImprovedGreedyInput.txt outputbadImprovedGreedy2.txt 1
	


clean:
	rm -rf submission
