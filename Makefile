
all: 
	@$(MAKE) -C libs all
	@$(MAKE) -C tests all


clean:
	@$(MAKE) -C libs clean
	@$(MAKE) -C tests clean

debug: all
	@$(MAKE) -C tests/soboot debug

.PHONY: clean all debug

