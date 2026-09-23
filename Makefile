all: football temperature
football: football.c
	gcc football.c -o football
temperature: temperature.c
	gcc temperature.c -o temperature
clean:
	rm -f football temperature