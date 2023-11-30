# Top-level Makefile

.PHONY: all clean

all:
	$(MAKE) -C output/

clean:
	$(MAKE) -C output/ clean
