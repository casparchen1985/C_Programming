.PHONY: clean All

All:
	@echo "----------Building project:[ L68-FindPrimeNumber - Debug ]----------"
	@cd "L68-FindPrimeNumber" && "$(MAKE)" -f  "L68-FindPrimeNumber.mk"
clean:
	@echo "----------Cleaning project:[ L68-FindPrimeNumber - Debug ]----------"
	@cd "L68-FindPrimeNumber" && "$(MAKE)" -f  "L68-FindPrimeNumber.mk" clean
