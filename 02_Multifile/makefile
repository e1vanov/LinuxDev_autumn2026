GENERATES = prog prog-a prog-so liboutput_static.a liboutput.so README
TRASH = *.o *~ o.* outfile*
CFLAGS = -Wall

all:	README prog liboutput_static.a liboutput.so prog-a prog-so

prog:	const.o fun.o prog.o

prog-a:	prog.o liboutput_static.a
		cc -L. -loutput_static prog.o -o prog-a

prog-so:	prog.o liboutput.so
		cc -L. prog.o -loutput -o prog-so

README:	prog
		./$< 2> $@

fun.o:	outlib.h

liboutput_static.a:	const.o fun.o
		ar -rcs liboutput_static.a const.o fun.o

liboutput.so:		const.c fun.c
		cc -fPIC -c const.c -o const_dyn.o
		cc -fPIC -c fun.c -o fun_dyn.o
		cc -shared fun_dyn.o const_dyn.o -o liboutput.so

TEST_SINGLE_ARG = HelloWorld
TEST_TRIPLE_ARG = HelloWorld1 HelloWorld2 HelloWorld3

test:	prog prog-a prog-so	
		./prog > outfile 2>&1
		./prog-a > outfile_a 2>&1
		./prog-so > outfile_so 2>&1
		./prog $(TEST_SINGLE_ARG) > outfile_single
		./prog-a $(TEST_SINGLE_ARG) > outfile_single_a
		./prog-so $(TEST_SINGLE_ARG) > outfile_single_so
		./prog $(TEST_TRIPLE_ARG) > outfile_triple
		./prog-a $(TEST_TRIPLE_ARG) > outfile_triple_a
		./prog-so $(TEST_TRIPLE_ARG) > outfile_triple_so
		cmp outfile outfile_a
		cmp outfile outfile_so
		cmp outfile_single outfile_single_a
		cmp outfile_single outfile_single_so
		cmp outfile_triple outfile_triple_a
		cmp outfile_triple outfile_triple_so

clean:
		rm -f $(TRASH)
		rm -rf $(GENERATES)
