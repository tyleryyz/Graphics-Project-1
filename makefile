all: ppmrw.c
	gcc ppmrw.c -o ppmrw

clean:
	rm -rf ppmrw.c *~
