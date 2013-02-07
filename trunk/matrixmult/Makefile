CC = g++
targets = MatrixMult1 MatrixMult2 TimerOnly CLike1 CLike2 CLike3 CompileTime

all: $(targets)

$(targets):
	g++ -O99 -fconstexpr-depth=9300 -ftemplate-depth=9000 $@.cpp -o $@ -std=c++11

clean:
	rm $(targets)

test:
	make -s test-delegate

test-delegate:
	:> results.txt;\
	$(foreach e, $(targets), \
	echo $(e) ;\
	for i in {1..100}; do $(CURDIR)/$(e); done |\
	awk '/time/ { total += $$2} /time/ { print $$2 } END {print "$(e) average: " total/100 "\n"}' |\
	 tee -a results.txt; )\
	echo "Summary of averages: " ; \
	{ $(foreach e, $(targets), \
	awk '/$(e) average/ { print "$(e) " $$3 }' results.txt | column -t ; ) } |\
	sort -k2n | column -t
