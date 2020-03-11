all: libs tests

libs tests:
	@$(MAKE) -C $@ test

.PHONY: libs tests

