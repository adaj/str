set autoscale
set title "Desempenho de ordenação - Algoritmo Quicksort"
set xlabel "Amostras"
set ylabel "Tempo de CPU (ms)"
plot "ord_data.txt" using 1:2 title 'Quicksort' with linespoints
