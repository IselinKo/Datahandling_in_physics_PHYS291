all:  mam2019org  mam2019mod   virt  not_virt  testvirt


mam2019org:  mammals2019org.cpp
	echo "compiling also  mammals2019org.cpp   to       mam2019org"
	g++ -o mam2019org mammals2019org.cpp

mam2019mod:  mammals2019mod.cpp
	echo "compiling also  mammals2019mod.cpp   to       mam2019mod"
	g++ -o mam2019mod mammals2019mod.cpp


virt : mammal_virt.cpp  Makefile
	echo "compiling  mammal_virt.cpp   to  ./virt  "
	g++ -o virt mammal_virt.cpp 	

not_virt : mammal_not_virt.cpp  Makefile
	echo "mammal_not_virt.cpp   to  ./not_virt  "
	g++ -o not_virt mammal_not_virt.cpp 	

testvirt:   mammal_not_virt.cpp  mammal_virt.cpp virt not_virt
	echo "running    ./virt  > virt_out.txt  and   ./not_virt > not_virt_out.txt"
	echo "producing two output files  virt_out.txt    and   not_virt_out.txt "
	./virt  > virt_out.txt
	./not_virt > not_virt_out.txt
	echo "performs  diff  virt_out.txt not_virt_out.txt"
	- diff  virt_out.txt   not_virt_out.txt 2>/dev/null
	echo "test finished"
	echo "The error possibly issued by Make is not a real error,  results from diff"

#   the -  sign in    - diff  virt_out.txt   not_virt_out.txt
#   is necessary to prevent an error message from make
#   Found at stack overflow

clean:
	rm -f virt  not_virt  mam2019org  mam2019mod  virt_out.txt   not_virt_out.txt

