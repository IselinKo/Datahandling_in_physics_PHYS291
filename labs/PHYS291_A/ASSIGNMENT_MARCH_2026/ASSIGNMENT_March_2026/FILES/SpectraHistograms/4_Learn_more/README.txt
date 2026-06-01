
hist_to_gra_1_W.C               histogram to graph (if needed?)

Multi_Hist_to_Gra_1_W.C         3 histograms stacked vs 3 graphs
                                Graphs are more apparent

mult_graph_wi_lines2020.C       adding lines to multigraph
                                (enhancing results)
                                (similar to extragr_p2.C in 1_fitting_example)

The functions, their parameters, functions in fit, "Cloning" 
Also how to proceed with a script in steps, showing graphics in steps

pitfall.C              
distribPitf.C  ( destroy_distrib.C you call from distribPitf.C )
cloned_no_pit.C
All these files show imperfections, running into pitfalls
(   the pitfall.C shows a funny case: the results are fine, until you click)
    (  demonstrates also that graphics "lives its own life of updates")

What you can learn here:   WITHOUT THIS, the graphics NOT SHOWN until the end !!!!
      canv->Modified();canv->Update();  gSystem->ProcessEvents();
      getline(cin,dummy);                                         

make_osloETC.C      (actually as it is makes Roma.root, )
     
scalefact.C         scale functions - add an extra parameter etc

twopeaks.C         two peaks. create and then fit
N_twopeaks.C       two peaks create and fit; unsuccessful fits also shown; 
M_twopeaks.C       minor variation
