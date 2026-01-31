# ---------- Student 1 ----------

ExamplesProgram1: Student1.o ExamplesStudent1.o
	 gcc Student1.o ExamplesStudent1.o -o ExamplesProgram1

TestProgram1: Student1.o TestStudent1.o
	 gcc Student1.o TestStudent1.o -o TestProgram1

Student1.o: Student1.c Student1.h
	 gcc -c Student1.c -o Student1.o

ExamplesStudent1.o: ExamplesStudent1.c Student1.h
	 gcc -c ExamplesStudent1.c -o ExamplesStudent1.o

TestStudent1.o: TestStudent1.c Student1.h
	 gcc -c TestStudent1.c -o TestStudent1.o


# ---------- Student 2 ----------

ExamplesProgram2: Student2.o ExamplesStudent2.o
	 gcc Student2.o ExamplesStudent2.o -o ExamplesProgram2

TestProgram2: Student2.o TestStudent2.o
	 gcc Student2.o TestStudent2.o -o TestProgram2

Student2.o: Student2.c Student2.h
	 gcc -c Student2.c -o Student2.o

ExamplesStudent2.o: ExamplesStudent2.c Student2.h
	 gcc -c ExamplesStudent2.c -o ExamplesStudent2.o

TestStudent2.o: TestStudent2.c Student2.h
	 gcc -c TestStudent2.c -o TestStudent2.o


# ---------- Student 3 ----------

ExamplesProgram3: Student3.o ExamplesStudent3.o
	 gcc Student3.o ExamplesStudent3.o -o ExamplesProgram3

TestProgram3: Student3.o TestStudent3.o
	 gcc Student3.o TestStudent3.o -o TestProgram3

Student3.o: Student3.c Student3.h
	 gcc -c Student3.c -o Student3.o

ExamplesStudent3.o: ExamplesStudent3.c Student3.h
	 gcc -c ExamplesStudent3.c -o ExamplesStudent3.o

TestStudent3.o: TestStudent3.c Student3.h
	 gcc -c TestStudent3.c -o TestStudent3.o


# ---------- Student 4 ----------

ExamplesProgram4: Student4.o ExamplesStudent4.o
	 gcc Student4.o ExamplesStudent4.o -o ExamplesProgram4

TestProgram4: Student4.o TestStudent4.o
	 gcc Student4.o TestStudent4.o -o TestProgram4

Student4.o: Student4.c Student4.h
	 gcc -c Student4.c -o Student4.o

ExamplesStudent4.o: ExamplesStudent4.c Student4.h
	 gcc -c ExamplesStudent4.c -o ExamplesStudent4.o

TestStudent4.o: TestStudent4.c Student4.h
	 gcc -c TestStudent4.c -o TestStudent4.o


# ---------- Запуск всех примеров ----------

examples: ExamplesProgram1 ExamplesProgram2 ExamplesProgram3 ExamplesProgram4
	 ./ExamplesProgram1
	 ./ExamplesProgram2
	 ./ExamplesProgram3
	 ./ExamplesProgram4


# ---------- Запуск всех тестов ----------

tests: TestProgram1 TestProgram2 TestProgram3 TestProgram4
	./TestProgram1
	./TestProgram2
	./TestProgram3
	./TestProgram4


# ---------- Очистка ----------

clean:
	 rm -f *.o ExamplesProgram1 ExamplesProgram2 ExamplesProgram3 ExamplesProgram4 \
 TestProgram1 TestProgram2 TestProgram3 TestProgram4
