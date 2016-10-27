amazing: Awesome.c
	gcc Awesome.c -o amazing

run: amazing
	./amazing

clean:
	rm *~ *.txt
