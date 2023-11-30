# Top-level Makefile

.PHONY: all clean

all:
	cd output && cmake . && $(MAKE)

clean:
	rm -rf r-type_client &&	rm -rf r-type_server
