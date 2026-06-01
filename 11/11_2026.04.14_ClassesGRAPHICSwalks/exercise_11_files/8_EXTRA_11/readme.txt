graph_interact_fail.C
main_only.cpp         can compile by g++; would not run in root
                      in some versions it can be .L main_only.cpp
                         and then in root   main() 
                         however that crashes in some versions of root
                         (because  main()   is refering to main of root)
main_smain.cpp        This works, in root the main()  becomes main_smain()
                      look at the source;  this can be useful
graph_interact_fail.C     root graph_interact_fail.C    NO GRAPHICS until the end
vgraph_interacDEF.C       works as expected   
               look also at the back_forthGRAPH*.C in ENTER_key_ANIMATION/

