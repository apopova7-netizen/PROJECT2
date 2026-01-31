CC = gcc

ExamplesProgram%: Student%.o ExamplesStudent%.o
	$(CC) Student$*.o ExamplesStudent$*.o -o ExamplesProgram$*


TestProgram%: Student%.o TestStudent%.o
	$(CC) Student$*.o TestStudent$*.o -o TestProgram$*


Student%.o: Student%.c Student%.h
	$(CC) -c Student$*.c -o Student$*.o

ExamplesStudent%.o: ExamplesStudent%.c Student%.h
	$(CC) -c ExamplesStudent$*.c -o ExamplesStudent$*.o

TestStudent%.o: TestStudent%.c Student%.h
	$(CC) -c TestStudent$*.c -o TestStudent$*.o


examples: ExamplesProgram1 ExamplesProgram2 ExamplesProgram3 ExamplesProgram4
	./ExamplesProgram1
	./ExamplesProgram2
	./ExamplesProgram3
	./ExamplesProgram4

tests: TestProgram1 TestProgram2 TestProgram3 TestProgram4
	./TestProgram1
	./TestProgram2
	./TestProgram3
	./TestProgram4

clean:
	rm -f *.o ExamplesProgram1 ExamplesProgram2 ExamplesProgram3 ExamplesProgram4 \
	TestProgram1 TestProgram2 TestProgram3 TestProgram4