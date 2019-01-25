#include "gnuPlot.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
void plotData(string file){
  gnuplot p;
  p("set term postscript eps");
  p("set output \"out3.eps\" ");
  p("plot \"./out3.dat\" ");
}
int main(){
  plotData("out3");


  return 0;
}
