.PHONY: clean All

All:
	@echo "----------Building project:[ L79-SomeFunctions - Debug ]----------"
	@cd "L79-SomeFunctions" && "$(MAKE)" -f  "L79-SomeFunctions.mk"
clean:
	@echo "----------Cleaning project:[ L79-SomeFunctions - Debug ]----------"
	@cd "L79-SomeFunctions" && "$(MAKE)" -f  "L79-SomeFunctions.mk" clean
