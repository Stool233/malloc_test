# malloc_test

```
gcc -g malloc_test1.c -o malloc_test1 -lpthread
```

```
gdb --batch --pid `pidof malloc_test1` --ex 'call malloc_trim()'
```

```
stap ./stap/trace_madvise.stp -x `pidof malloc_test1`
```

```
bash ./hook/build.sh
LD_PRELOAD=./hook/my_malloc.so ./malloc_test1
```