all: submission

p1: submission.cpp
	g++ -g submission.cpp -o submission
	./submission smallInput.txt smallOutputGreedy2.txt 1
	./submission smallInput.txt smallOutputBacktracking.txt 2
	./submission input.txt outputGreedy2.txt 1
	./submission input.txt outputBacktracking.txt 2
	./submission mediumInput.txt mediumOutputGreedy2.txt 1
	./submission mediumInput.txt mediumOutputBacktracking.txt 2
	./submission smallInput.txt smallOutputGreedy2.txt 2
	./submission badGreedyInput.txt outputbadGreedy1.txt 0
	./submission badGreedyInput.txt outputbadGreedy2.txt 1
	./submission badImprovedGreedyInput.txt outputbadImprovedGreedy2.txt 1
	


clean:
	rm -rf submission
