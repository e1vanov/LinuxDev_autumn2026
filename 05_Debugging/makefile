range: range.c
	cc -O0 -g range.c -o range

test: range
	cmp -s <(gdb -x test_script_01.gdb ./range | grep @@@) test_01_ref && echo "Test #1 passed"
	cmp -s <(gdb -x test_script_02.gdb ./range | grep @@@) test_02_ref && echo "Test #2 passed"

clean:
	rm -f *.o range

