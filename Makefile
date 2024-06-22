.PHONY: clean All

All:
	@echo "----------Building project:[ L71-SimpleWeatherProgram - Debug ]----------"
	@cd "L71-SimpleWeatherProgram" && "$(MAKE)" -f  "L71-SimpleWeatherProgram.mk"
clean:
	@echo "----------Cleaning project:[ L71-SimpleWeatherProgram - Debug ]----------"
	@cd "L71-SimpleWeatherProgram" && "$(MAKE)" -f  "L71-SimpleWeatherProgram.mk" clean
