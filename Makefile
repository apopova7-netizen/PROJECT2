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

Student4.o: src/Student4.c include/Student4.h include/Student3.h include/Student2.h include/Student1.h
	$(CC) -Iinclude -c src/Student4.c -o Student4.o


ExamplesProgram4: Student4.o ExamplesStudent4.o Student3.o Student2.o Student1.o
	$(CC) Student4.o ExamplesStudent4.o Student3.o Student2.o Student1.o -o ExamplesProgram4


TestProgram4: Student4.o TestStudent4.o Student3.o Student2.o Student1.o
	$(CC) Student4.o TestStudent4.o Student3.o Student2.o Student1.o -o TestProgram4



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



