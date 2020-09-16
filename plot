reset

set terminal png size 800,600
set grid
set key out horiz
set logscale y

set format y "10^%T";
set xtics ("1x10^5" 100000, "2x10^5" 200000, "3x10^5" 300000, "4x10^5" 400000, "5x10^5" 500000, "6x10^5" 600000, "7x10^5" 700000, "8x10^5" 800000, "9x10^5" 900000, "10x10^5" 1000000)
set xrange [50000:1050000]
set yrange [0.1:1000]
set xlabel "Tamaño del conjunto" font ",18"
set ylabel "Tiempo (log) [us]" font ",18"

set key font ",16"
set tics font ",12"

set style line 1 linecolor rgb "blue" dashtype 8 linewidth 1.5 pointtype 5 pointsize 1.5
set style line 2 linecolor rgb "red" dashtype 8 linewidth 1.5 pointtype 5 pointsize 1.5
set style line 3 linecolor rgb "dark-chartreuse" dashtype 8 linewidth 1.5 pointtype 5 pointsize 1.5

set output 'grafica_aleatorio.png'
plot 'data_aleatorio' u 1:2 w lp t 'linear' ls 1, '' u 1:3 w lp t 'binary' ls 2, '' u 1:4 w lp t 'doubling' ls 3

set output 'grafica_inicio.png'
plot 'data_inicio' u 1:2 w lp t 'linear' ls 1, '' u 1:3 w lp t 'binary' ls 2, '' u 1:4 w lp t 'doubling' ls 3

set output 'grafica_medio.png'
plot 'data_medio' u 1:2 w lp t 'linear' ls 1, '' u 1:3 w lp t 'binary' ls 2, '' u 1:4 w lp t 'doubling' ls 3

set output 'grafica_fin.png'
plot 'data_fin' u 1:2 w lp t 'linear' ls 1, '' u 1:3 w lp t 'binary' ls 2, '' u 1:4 w lp t 'doubling' ls 3
