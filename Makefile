
EXERCISES = ex00 ex01 ex02

all: 
	@for ex in $(EXERCISES); do \
		echo "===== Building $$ex ====="; \
		$(MAKE) -C $$ex; \
		echo " ===== $$ex built =====\n"; \
	done

clean:
	@for ex in $(EXERCISES); do \
		echo "===== Cleaning $$ex ====="; \
		$(MAKE) -C $$ex clean; \
		echo " ===== $$ex cleaned =====\n"; \
	done

fclean:
	@for ex in $(EXERCISES); do \
		echo "===== Cleaning $$ex ====="; \
		$(MAKE) -C $$ex fclean; \
		echo " ===== $$ex cleaned =====\n"; \
	done

re: fclean all

.PHONY: all clean fclean re
