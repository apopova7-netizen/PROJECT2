CC = gcc
CFLAGS = -Iinclude

ALL = Student1.o Student2.o Student3.o Student4.o

ExamplesProgram4: $(ALL) ExamplesStudent4.o
	$(CC) $(ALL) ExamplesStudent4.o -o ExamplesProgram4

ExamplesProgram%: Student%.o ExamplesStudent%.o
	$(CC) Student$*.o ExamplesStudent$*.o -o ExamplesProgram$*

TestProgram%: Student%.o TestStudent%.o
	$(CC) Student$*.o TestStudent$*.o -o TestProgram$*

Student%.o: src/Student%.c include/Student%.h
	$(CC) $(CFLAGS) -c src/Student$*.c -o Student$*.o

ExamplesStudent%.o: examples/ExamplesStudent%.c include/Student%.h
	$(CC) $(CFLAGS) -c examples/ExamplesStudent$*.c -o ExamplesStudent$*.o

TestStudent%.o: tests/TestStudent%.c include/Student%.h
	$(CC) $(CFLAGS) -c tests/TestStudent$*.c -o TestStudent$*.o

examples: ExamplesProgram1 ExamplesProgram2 ExamplesProgram3 ExamplesProgram4
	./ExamplesProgram1
	./ExamplesProgram2
	./ExamplesProgram3
	./ExamplesProgram4

tests: TestProgram1 TestProgram2 TestProgram3 TestProgram4
	./TestProgram1
	./TestProgram2
	./TestProgram3


clean:
	rm -f *.o ExamplesProgram1 ExamplesProgram2 ExamplesProgram3 ExamplesProgram4 \
	TestProgram1 TestProgram2 TestProgram3

