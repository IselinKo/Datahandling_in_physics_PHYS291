
all: start

start:
	root -q root_to_webN.C

stop: 
	rm -f swap; mKILL python 9

go:
	python3 -m http.server 8000 &

anim:
	cp -f nswap swap; ./swap &	

clean:
	rm -f *.png *.html swap;	mKILL python  9 
