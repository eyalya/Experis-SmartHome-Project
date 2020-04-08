
all: 
	@$(MAKE) -C libs all
	@$(MAKE) -C tests all


clean:
	@$(MAKE) -C libs clean
	@$(MAKE) -C tests clean

debug:
	@$(MAKE) -C tests/publisher debug


#git change

.PHONY: clean all debug

