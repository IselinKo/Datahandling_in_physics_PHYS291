C  file comp.f
C  SIMPLE Fortran example
C  compile by    gfortran -o fortran_comp comp.f
C  run by:       ./fortran_comp
C
      integer i
      do i=1,10
             write(*,'( I3, 3x, I5 )') i, i*i
      end do
      end


