.PHONY: clean All

All:
	@echo "----------Building project:[ L81-TicTacToe - Debug ]----------"
	@cd "L81-TicTacToe" && "$(MAKE)" -f  "L81-TicTacToe.mk"
clean:
	@echo "----------Cleaning project:[ L81-TicTacToe - Debug ]----------"
	@cd "L81-TicTacToe" && "$(MAKE)" -f  "L81-TicTacToe.mk" clean
