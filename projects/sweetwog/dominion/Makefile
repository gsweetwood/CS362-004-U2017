CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

#testdom1: domintion.o playdom.c
#	gcc -o testdom1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
#
#unittest1.o: unittest1.c
#	gcc -c unittest1.c -g $(CFLAGS)
#
#testdom2: dominion.o playdom.c
#	gcc -o testdom2 unittest.c -g dominion.o rngs.o $(CFLAGS)
#
#unittest2.o: unittest2.c
#	gcc -c unittest2.c -g $(CFLAGS)
#
#t1: testdom
#	./testdom1 >> unittestresults.out
#	./testdom2 >> unittestresults.out
#	gcov -b -c unittest1.c >> unittestresults.out
#	gcov -b -c unittest2.c >> unittestresults.out

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard 

unittest1: unittest1.c dominion.o rngs.o interface.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o interface.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o interface.o
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o interface.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o interface.o
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o interface.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o interface.o
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o rngs.o interface.o
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o interface.o
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o interface.o
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o interface.o
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o interface.o $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o interface.o
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o interface.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o interface.o
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o interface.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o interface.o
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o interface.o $(CFLAGS)

randomtestadventurer.out: randomtestadventurer.c dominion.c rngs.o interface.o
	echo "Results for randomtestadventurer: " > randomtestadventurer.out

	
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	gcov -b dominion.c >> randomtestadventurer.out

randomtestcard2.out: randomtestcard2.c dominion.c rngs.o interface.o
	echo "Results for randomtestcard2: " > randomtestcard2.out

	gcc -o randomtestcard2 randomtestcard2.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./randomtestcard2 >> randomtestcard2.out
	gcov -b dominion.c >> randomtestcard2.out

randomtestcard1.out: randomtestcard1.c dominion.c rngs.o interface.o
	echo "Results for randomtestcard1: " > randomtestcard1.out

	gcc -o randomtestcard1 randomtestcard1.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./randomtestcard1 >> randomtestcard1.out
	gcov -b dominion.c >> randomtestcard1.out



unittestresults.out: cardtest1.c cardtest2.c cardtest3.c cardtest4.c unittest1.c unittest2.c unittest3.c unittest4.c dominion.c rngs.o interface.o
	echo “Results for unit tests:” > unittestresults.out

	echo “unittest1.c” >> unittestresults.out
	gcc -o unittest1 unittest1.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	echo “unittest2.c” >> unittestresults.out
	gcc -o unittest2 unittest2.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	echo “unittest3.c” >> unittestresults.out
	gcc -o unittest3 unittest3.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	
	echo “unittest4.c” >> unittestresults.out
	gcc -o unittest4 unittest4.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	echo “cardtest1.c” >> unittestresults.out
	gcc -o cardtest1 cardtest1.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	echo “cardtest2.c” >> unittestresults.out
	gcc -o cardtest2 cardtest2.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	echo “cardtest3.c” >> unittestresults.out
	gcc -o cardtest3 cardtest3.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	echo “cardtest4.c” >> unittestresults.out
	gcc -o cardtest4 cardtest4.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
clean:
	rm -f *.o playdom.exe playdom player player.exe unittest1.exe unittest1 unittest2.exe unittest2 unittest3.exe unittest3 unittest4.exe unittest4 cardtest1.exe cardtest1 cardtest2.exe cardtest2 cardtest3.exe cardtest3 cardtest4.exe cardtest4 randomtestcard1.exe randomtestcard1 randomtestcard2.exe randomtestcard2 randomtestadventurer.exe randomtestadventurer  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
