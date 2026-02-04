CC = gcc

ExamplesProgram%: Student%.o ExamplesStudent%.o
	$(CC) Student$*.o ExamplesStudent$*.o -o ExamplesProgram$*


TestProgram%: Student%.o TestStudent%.o
	$(CC) Student$*.o TestStudent$*.o -o TestProgram$*


Student%.o: src/Student%.c include/Student%.h
	$(CC) -Iinclude -c src/Student$*.c -o Student$*.o

ExamplesStudent%.o: examples/ExamplesStudent%.c include/Student%.h
	$(CC) -Iinclude -c examples/ExamplesStudent$*.c -o ExamplesStudent$*.o

TestStudent%.o: tests/TestStudent%.c include/Student%.h
	$(CC) -Iinclude -c tests/TestStudent$*.c -o TestStudent$*.o


examples: ExamplesProgram1 ExamplesProgram2 ExamplesProgram3 ExamplesProgram4
	./ExamplesProgram1
	./ExamplesProgram2
	./ExamplesProgram3
	./ExamplesProgram4

tests: TestProgram1 TestProgram2 TestProgram3 
	./TestProgram1
	./TestProgram2
	./TestProgram3

clean:
	rm -f *.o ExamplesProgram1 ExamplesProgram2 ExamplesProgram3 ExamplesProgram4 \
	TestProgram1 TestProgram2 TestProgram3 




