newobj: sample_dec2021.c
	gcc $^ -lpthread -o $@

clean:
	rm -f newobj
