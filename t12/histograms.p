set autoscale
set style data histograms
set title "Amostragens do desempenho dos algoritmos de ordenação dado 100 amostras de dados"
plot "hist.dat" using 2 title 'Bubblesort', "hist.dat" using 1 title 'Quicksort'
