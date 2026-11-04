set pagination off
set $_out_idx=0
b 8
command 1
        set $_out_idx=$_out_idx+1
        if $_out_idx>=28 && $_out_idx<=35
            printf "@@@ %d %d %d %d\n", m, n, s, i
        end
        cont
end

run -100 100 3 > /dev/null
quit
