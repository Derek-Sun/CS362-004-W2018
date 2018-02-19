CFLAGS = -Wall -fpic -coverage -lm
rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)
dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)
unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
randomtest1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
randomtest2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)
randomAdventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)
badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)
testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)
testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)
interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)
runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

runrandomtest: randomtest1 randomtest2 randomAdventurer unittest1 unittest2 unittest3
	./unittest1 > unittestresults.out
	gcov unittest1 -abcfu >> unittestresults.out
	./unittest2 >> unittestresults.out
	gcov unittest1 -abcfu >> unittestresults.out
	./unittest3 >> unittestresults.out
	gcov unittest1 -abcfu >> unittestresults.out
	gcov dominion.c -abcfu >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	./randomtestcard1 >> unittestresults.out
	gcov randomtestcard1 -abcfu >> unittestresults.out
	cat randomtestcard1.c.gcov >> unittestresults.out
	gcov dominion.c -abcfu >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out	
	./randomtestcard2 >> unittestresults.out
	gcov randomtestcard2 -abcfu >> unittestresults.out
	cat randomtestcard2.c.gcov >> unittestresults.out
	gcov dominion.c -abcfu >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out	
	./randomtestadventurer >> unittestresults.out
	gcov randomtestadventurer -abcfu >> unittestresults.out
	cat randomtestadventurer.c.gcov >> unittestresults.out
	gcov dominion.c -abcfu >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out	

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)
all: playdom player testDrawCard testBuyCard badTestDrawCard randomtest1 randomtest2 randomAdventurer runrandomtest unittest1 unittest2 unittest3
clean:
	rm -f *.o playdom.exe playdom player player.exe randomtestcard1 randomtestcard2 randomtestadventurer unittest1 unittest2 unittest3 badTestDrawCard badTestDrawCard.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe