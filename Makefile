.PHONY: clean All

All:
	@echo "----------Building project:[ L58-CalculateTax - Debug ]----------"
	@cd "l58-Tax" && "$(MAKE)" -f  "L58-CalculateTax.mk"
clean:
	@echo "----------Cleaning project:[ L58-CalculateTax - Debug ]----------"
	@cd "l58-Tax" && "$(MAKE)" -f  "L58-CalculateTax.mk" clean
