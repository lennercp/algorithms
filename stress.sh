make gen;make $1;make $2;

expected_output="YES"
for((i = 1; ; i++)); do
    echo $i
    ./gen $i > a.txt
    
    diff -w <(./$1 < a.txt) <(./$2 < a.txt) || break

    # caso queira rodar $1 e $2 ser o checker
    # ./"$1" < a.txt > intermediate.txt
    # output=$(./"$2" < intermediate.txt)

    # # Compara saída com string desejada
    # if [[ "$output" != "$expected_output" ]]; then
    #     echo "Falha no teste $i"
    #     echo "Saída do $2 foi: $output"
    #     break
    # fi
done
