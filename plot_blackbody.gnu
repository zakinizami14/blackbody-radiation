set title "Blackbody Radiation Spectrum"
set xlabel "Wavelength (μm)"
set ylabel "Spectral Energy Density (W/m^3)"
set grid

set key top right

plot "blackbody.dat" using 1:2 with lines title "T=3000K" lw 2 lc rgb "red", \
     "blackbody.dat" using 1:3 with lines title "T=4000K" lw 2 lc rgb "blue", \
     "blackbody.dat" using 1:4 with lines title "T=5000K" lw 2 lc rgb "green"
