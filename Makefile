all: build

config:
	./configure

build:
	$(MAKE) -C build/

test:
	$(MAKE) -C build/ test

doc:
	$(MAKE) -C build/ doc

install:
	$(MAKE) -C build/ install

clean:
	$(MAKE) -C build/ clean

%:
	$(MAKE) -C build/ $@

.PHONY: all config build test doc install clean
