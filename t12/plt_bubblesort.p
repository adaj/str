set autoscale
set title "Desempenho de ordenação - Algoritmo Bubblesort"
set xlabel "Amostras"
set ylabel "Tempo de CPU (ms)"
plot "ord_data.txt" using 1:3 title 'Bubblesort' with linespoints
