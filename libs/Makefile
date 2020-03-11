all: sprinkler smokeDetector 
test: sprinkler smokeDetector

sprinkler smokeDetector:
	@$(MAKE) -C $@ test

clean:
	@$(MAKE) -C $@ clean

.PHONY: clean sprinkler smokeDetector

