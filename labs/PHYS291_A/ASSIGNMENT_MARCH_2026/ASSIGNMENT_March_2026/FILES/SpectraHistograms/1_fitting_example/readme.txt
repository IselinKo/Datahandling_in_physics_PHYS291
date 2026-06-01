p2_hist_fit.C,  p2b_hist_fit.C, p2R_hist_fit.C

p2_hist_fit.C         p2b_hist_fit.C  and  p2R_hist_fit.C  are nearly identical
on fitting1.root      on Bergen.root       on Roma.root

extragr_p2.C     makes the FWHM on any variant of  p2_hist_fit.C
                 (modifies the cloned histogram drawing)
                 Now added to all three by ProcessLine( )

diff_p2_p2b_hist.txt      is the  difference of p2_hist_fit.C p2b_hist_fit.C
 
All three write to a file report.txt
( perhaps one could make report2.txt  with the peak value, width and position
  instead of p0,p1,p2,p3,p4 )

The name of the histogram must be found  (file root_test_1.C )
        for the automatic search for Histogram names  - KEYS )

p1_hist.C  was used to make the fitting1.root   (you can make other such files, Berlin.root ....)


