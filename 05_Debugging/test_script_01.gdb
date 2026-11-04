set pagination off
b 8 if i % 5 == 0
command 1
        printf "@@@ %d %d %d %d\n", m, n, s, i
        cont
end

run 1 12 > /dev/null
quit
